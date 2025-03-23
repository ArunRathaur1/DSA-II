require("dotenv").config();
const puppeteer = require("puppeteer");
const axios = require("axios");
const { GoogleGenerativeAI } = require("@google/generative-ai");

// Load environment variables
const GFG_USERNAME = process.env.GFG_USERNAME;
const GFG_PASSWORD = process.env.GFG_PASSWORD;
const GEMINI_API_KEY = process.env.GEMINI_API_KEY;

const genAI = new GoogleGenerativeAI(GEMINI_API_KEY);
const model = genAI.getGenerativeModel({ model: "gemini-1.5-flash" });

/**
 * Fetches 5 random problems from GeeksforGeeks (sample problems).
 */
async function fetchGFGProblems() {
  try {
    const response = await axios.get(
      "https://practice.geeksforgeeks.org/problems"
    );
    const problems = response.data.match(/\/problems\/[a-zA-Z0-9-]+/g);
    const uniqueProblems = [...new Set(problems)];
    return uniqueProblems
      .slice(0, 5)
      .map((p) => `https://practice.geeksforgeeks.org${p}`);
  } catch (error) {
    console.error("❌ Error fetching GFG problems:", error.message);
    return [];
  }
}

/**
 * Generates a C++ solution for a given problem using Gemini AI.
 */
async function generateSolution(problemUrl) {
  try {
    const prompt = `Write an optimal C++ solution for the following problem: ${problemUrl}. No explanation, just the code.`;

    const result = await model.generateContent(prompt);
    const response = await result.response;
    return response.text();
  } catch (error) {
    console.error("❌ Error generating solution:", error.message);
    return "Failed to generate solution.";
  }
}

/**
 * Logs into GeeksforGeeks and submits a solution using Puppeteer.
 */
async function submitToGFG(problemUrl, solution) {
  const browser = await puppeteer.launch({ headless: false }); // Set to 'true' if you want it to run in the background
  const page = await browser.newPage();

  try {
    // Navigate to GFG login page
    await page.goto("https://auth.geeksforgeeks.org/", { waitUntil: "load" });

    // Enter login details
    await page.type("#email", GFG_USERNAME, { delay: 50 });
    await page.type("#password", GFG_PASSWORD, { delay: 50 });
    await page.click('button[type="submit"]');

    // Wait for login to complete
    await page.waitForNavigation({ waitUntil: "domcontentloaded" });

    console.log("✅ Logged into GeeksforGeeks");

    // Open the problem page
    await page.goto(problemUrl, { waitUntil: "load" });

    // Click on the submit button (if needed)
    await page.waitForSelector(".submit-code-btn");
    await page.click(".submit-code-btn");

    // Wait for the code editor to load
    await page.waitForSelector(".ace_text-input");

    // Paste the generated solution
    await page.type(".ace_text-input", solution, { delay: 10 });

    // Submit the code
    await page.click(".submit-button");

    console.log(`✅ Submitted solution for: ${problemUrl}`);

    await browser.close();
  } catch (error) {
    console.error("❌ Error submitting solution:", error.message);
    await browser.close();
  }
}

/**
 * Main function: Fetch problems, generate solutions, and submit them.
 */
(async () => {
  const problems = await fetchGFGProblems();
  for (const problem of problems) {
    const solution = await generateSolution(problem);
    if (solution !== "Failed to generate solution.") {
      await submitToGFG(problem, solution);
    }
  }
})();

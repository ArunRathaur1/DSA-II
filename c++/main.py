from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# Constants
START_ROLL_NO = 23115001
END_ROLL_NO = 23115114
URL = "https://mis.nitrr.ac.in/iitmsoBF2zO1QWoLeV7wV7kw7kcHJeahVjzN4t6MFMeyhUykpKfBA9V+F0/3m6SMOr7hf?enc=2vjcaEnhmvfs4iwSJr18eQaN1iwTCkDZLg4FpnIV12/vTB0HoHDs8kZdmyK5DB9t"
DOWNLOAD_DIR = "./downloads"

def setup_driver():
    """Sets up the Selenium WebDriver with required options."""
    options = webdriver.ChromeOptions()
    prefs = {"download.default_directory": DOWNLOAD_DIR}  # Set download directory
    options.add_experimental_option("prefs", prefs)
    driver = webdriver.Chrome(options=options)
    return driver

def download_results(driver, roll_no):
    """Automates entering the roll number and downloading the result."""
    try:
        driver.get(URL)
        
        # Wait for the input field to be visible
        wait = WebDriverWait(driver, 10)
        roll_no_field = wait.until(EC.presence_of_element_located((By.ID, "txtRengo")))

        # Enter the roll number
        roll_no_field.clear()
        roll_no_field.send_keys(str(roll_no))

        # Click the "Show Result" button
        show_result_button = driver.find_element(By.ID, "btnimgshow")
        show_result_button.click()

        # Wait for the PDF to be downloadable
        wait.until(EC.presence_of_element_located((By.LINK_TEXT, "Download PDF")))
        pdf_link = driver.find_element(By.LINK_TEXT, "Download PDF")
        pdf_link.click()
        
        time.sleep(2)  # Give time for the file to download
    except Exception as e:
        print(f"An error occurred for roll number {roll_no}: {e}")

def main():
    driver = setup_driver()
    
    for roll_no in range(START_ROLL_NO, END_ROLL_NO + 1):
        print(f"Processing roll number: {roll_no}")
        download_results(driver, roll_no)

    driver.quit()

if __name__ == "__main__":
    main()

import os
import cv2
import pytesseract
from pytesseract import Output
import re
from difflib import SequenceMatcher
from hashlib import sha256


# Ensure Tesseract is correctly configured
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'  # Adjust the path if needed


def extract_text_from_frame(frame):
    custom_config = r'--oem 3 --psm 6'
    return pytesseract.image_to_data(frame, config=custom_config, output_type=Output.DICT)


def is_similar_text(text1, text2, threshold=0.8):
    return SequenceMatcher(None, text1, text2).ratio() > threshold


def get_unique_hash(text):
    return sha256(text.encode('utf-8')).hexdigest()


def process_video(video_path, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    video = cv2.VideoCapture(video_path)
    fps = video.get(cv2.CAP_PROP_FPS)
    total_frames = int(video.get(cv2.CAP_PROP_FRAME_COUNT))

    screenshot_count = 0
    unique_hashes = set()

    print(f"Processing video: {video_path}")
    print(f"Total frames: {total_frames} | FPS: {fps}")

    try:
        for frame_no in range(total_frames):
            ret, frame = video.read()
            if not ret:
                break

            # Perform OCR on the frame
            data = extract_text_from_frame(frame)
            extracted_text = " ".join([data["text"][i] for i in range(len(data["text"])) if data["text"][i].strip()])

            if extracted_text:
                text_hash = get_unique_hash(extracted_text)

                # Save only unique questions
                if text_hash not in unique_hashes:
                    unique_hashes.add(text_hash)

                    # Check if the text contains a question and options
                    question_found = False
                    options_found = False

                    # Check for question (ends with ? or contains question words)
                    question_keywords = ['What', 'Which', 'Who', 'Where', 'When', 'Why', 'How']
                    for text in data["text"]:
                        if re.match(r'(What|Which|Who|Where|When|Why|How)', text, re.IGNORECASE) or "?" in text:
                            question_found = True
                            break

                    # Check for options (e.g., "A.", "B.", "C.", "D.")
                    options_pattern = re.compile(r'^[A-D]\.', re.IGNORECASE)
                    for text in data["text"]:
                        if options_pattern.match(text.strip()):
                            options_found = True
                            break

                    # If both question and options are found, save the screenshot
                    if question_found and options_found:
                        # Save the entire frame
                        filename = os.path.join(output_dir, f"screenshot_{screenshot_count}.jpg")
                        cv2.imwrite(filename, frame)  # Save the entire frame
                        screenshot_count += 1
                        print(f"Saved screenshot: {filename}")

            # Optionally stop after a set number of frames (for testing purposes)
            # if frame_no > 100:  # Adjust as needed
            #     break

    except Exception as e:
        print(f"Error processing video: {e}")
    finally:
        video.release()

    print(f"Processed video and saved {screenshot_count} unique screenshots.")


if __name__ == "__main__":
    video_path = input("Enter the path to the downloaded video: ")
    save_path = input("Enter the directory to save the screenshots: ")

    # Process the video
    process_video(video_path, save_path)

""" 
Author: Akshat Bhat
Date: 06-10-2022

Download your favourite music and audio from YouTube in mp3 format.

To run:
python YouTubeMusicDownloaderNew.py <Folder Path to save downloaded file in single quotes>

Example:
$ python YouTubeMusicDownloaderNew.py 'D:\Audio\Downloads'
"""

from pytube import YouTube 
from pytube.cli import on_progress
from moviepy.editor import *
import string
import os
import sys

def format_filename(s):
    valid_chars = "-_.() %s%s" % (string.ascii_letters, string.digits)
    filename = ''.join(c for c in s if c in valid_chars)
    return filename

n = len(sys.argv)
SAVE_PATH = os.path.join(os.environ["HOMEPATH"], "Desktop")
if n == 1:
    print(f"\nTaking default storage path as {SAVE_PATH}")
    print("\nIf you want a different storage path, enter the path: ", end="")
    user_path = input()
else:
    user_path = sys.argv[1]

if os.path.isdir(user_path):
        SAVE_PATH = user_path
else:
    print(f"\nInvalid path... taking default storage path as {SAVE_PATH}")

print("\nEnter YT Link: ", end="")
link = input()
video = YouTube(link, on_progress_callback=on_progress)
title = video.title
artist = video.author
print(f"\nFound video with title: {title} by {artist}\nDownloading...\n")
audio = video.streams.filter(subtype="mp4")
formatted_filename = format_filename(f'{artist} - {title}')

audio[0].download(SAVE_PATH, filename=f"{formatted_filename}.mp4")

mp3_file = f"{SAVE_PATH}/{formatted_filename}.mp3"
mp4_file = f"{SAVE_PATH}/{formatted_filename}.mp4"

videoclip = VideoFileClip(mp4_file)
audioclip = videoclip.audio
audioclip.write_audiofile(mp3_file)
audioclip.close()
videoclip.close()

print("Do you want to delete source mp4 file? (Y or N)")
choice = input().lower()
if choice == "y" or choice == "Y":
    os.remove(mp4_file)
    print("Source mp4 file deleted")
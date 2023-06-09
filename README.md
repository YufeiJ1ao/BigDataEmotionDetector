# BigDataEmotionDetector


Initial Idea:
By publish tweets or all kinds of other publicly available texts, human behaviour becomes predictable, because most of the emotional responses of humans are simple and stereotypical. Therefore can be study and analyse by machine learning models.


## Emotion Recognition Model

One proposed function of mental imagery is to make thoughts more emotionally evocative through sensory simulation. This can be helpful both in planning for future events and in remembering the past, but also a hindrance when thoughts become overwhelming and maladaptive, such as in anxiety disorders. Models of human cognition propose that mental imagery exists for aiding thought predictions by linking them to emotions, allowing us to simulate and ‘try out’ future scenarios, as if we are experiencing them and their resulting emotional outcomes, aiding us in decision making.

There are two types of emotion measurement and assessment tools: psychophysiological and self-report assessment. With the developments of relevant research, researchers have begun progressively shifting attention toward research on user emotion in human-computer interaction.

## Documentation 
Collect data from twitter or any social platforms to build the database of this project.
## Requirements

- Arduino Leonardo
- RGB LED ring light
- Python 3.x
- Arduino IDE
## Setup Instructions
For Arduino IDE
1. Connect the RGB LED ring light to the Arduino Leonardo. Ensure that the data pin of the ring light is connected to the appropriate pin on the Arduino Leonardo (as defined in the code).
2. Install the required libraries:
   - For the Arduino code: `Adafruit_NeoPixel`
   - For the Python code: `pyserial`
3. Upload the provided Arduino code to the Arduino Leonardo.
4. Modify the Python emotion detector code to detect emotions based on input text.
5. Establish a serial connection between the Python code and the Arduino Leonardo by providing the correct port name in the Python code.
6. Run the Python code to detect emotions. The detected emotion will be sent over serial communication to the Arduino Leonardo, which will update the LED color on the RGB LED ring light accordingly.
###
1.For python setup
###
```
import pandas as pd
import numpy as np
import serial
import neattext.functions as nfx
``` 
>Neattext is a Python library that is used to preprocess our dataset. Neattext will clean the text dataset by removing stop words and noise.

```
from sklearn.linear_model import LogisticRegression
from sklearn.naive_bayes import MultinomialNB
```

### scrape data from twitter using twitter api
This python code is specifically for analysing code for only this user: @pledis_17. This code allows user to scrape latest 100 tweets from one user.

![image](https://git.arts.ac.uk/storage/user/363/files/9627473d-01a3-49a5-91ab-a370f5fe6991)
##
### Collect data from twitter and write them into a csv file
###
By using code https://git.arts.ac.uk/21000412/BigDataEmotionDetector/blob/main/scrapehappytweets.py from this file. Try writing data into csv file.

However, this data collected were not as sterotypical, therefore those are not ideal case study for analyzing human emotions due to their inherent complexity and variability. 
###
By researching, I found a really good case study of studying human emotions using machine learning. This NLP Based Emotion Detection Model using Neattext and Scikit-learn. NLP stands for Natural Language Processing. It is a research project focus on human language and computers. Including disciplines such as sentiment analysis, named entity recognition, topic modeling, and text, classification.

# Project outcome

By Typing into the python code. Change the input string, for example type-in "i had a good day"
```
sample1 = "I had a good day"
pipe_lr.predict([sample1])
```
>This will predict the emotion of this sentence
```
res = pipe_lr.predict([sample1])[0]
print(str(res))
```
>Output the emotion with a string

```
arduino_port = 'COM3'
ser = serial.Serial(arduino_port,9600,timeout=1)
```
>Replace with the detected emotion string
```
ser.write(str(res).encode())  
```
>Send the emotion data to the Arduino
```
emo=print
ser.close() 
```
## Representing emotions with color

This idea was originally inspired by a video game called 'Detroit: Become Human'. 

###
###
Where the main characters are artifical intelligences, there is a ring light built on the side of their forehead. Which display their emotion/reaction toward events.

![283939798625547827](https://git.arts.ac.uk/storage/user/363/files/04c5393c-6a2b-4eb8-98ad-9ab1037da73b)
>Anger is represented by red

![766728504756798521](https://git.arts.ac.uk/storage/user/363/files/230f996c-adb2-4bdd-b16f-8b7b9989d07c)
>Fear is represented by purple

![565054597863093333](https://git.arts.ac.uk/storage/user/363/files/f018ad3b-84a9-458e-9d5d-940de7c5f615)
>Joy is represented by Mint Blue
>Etc.
>

## links and references
https://royalsocietypublishing.org/doi/10.1098/rspb.2021.0267
https://www.frontiersin.org/articles/10.3389/fpsyg.2021.772642/full
https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4595480/
https://www.section.io/engineering-education/nlp-based-detection-model-using-neattext-and-scikit-learn/#:~:text=The%20emotion%20detection%20model%20is,text%20into%20the%20following%20categories.
 

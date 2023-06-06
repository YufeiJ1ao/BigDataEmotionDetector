import pandas as pd
from tqdm.notebook import tqdm
import snscrape.modules.twitter as sntwitter

scraper = sntwitter.TwitterSearchScraper("#emotion")

for i, tweet in enumerate.get_items():
    break
tweets= []
data = [tweet.emotion, tweet.text,]

tweets.append(data)
if i > 50:
    break
tweet_df = pd.DataFrame(
    tweets, colums = ["emotion","text"]
)
tweet_df.to_csv("emotion-happy.csv", index=False)

#!/usr/bin/env python
# coding: utf-8

# In[1]:


import tweepy
import pandas as pd


# In[2]:


consumer_key = 'oTPICh7siAsXmzrwkgaFCcWkq'
consumer_secret = 'H5WwhkrsmSbnNsrPfGmiz53vZBbycwSGHfh6Y5i91MB9KVvhtPT'
access_token = '1521210752236933379-mSNYA8uz4psQrfWWYP6aQsBRJheftx'
access_token_secret = '8fegqe5sY5qEzjIC9GVaIeFsYmAXCeMfBskdBW2QpgNIh'


# In[3]:


auth = tweepy.OAuth1UserHandler(
    consumer_key, consumer_secret,
    access_token, access_token_secret
)
api = tweepy.API(auth, wait_on_rate_limit=True)
username = "pledis_17"
no_of_tweets =100


# In[4]:


try:
    #The number of tweets we want to retrieved from the user
    tweets = api.user_timeline(screen_name=username, count=no_of_tweets)
    
    #Pulling Some attributes from the tweet
    attributes_container = [[tweet.created_at, tweet.favorite_count,tweet.source,  tweet.text] for tweet in tweets]

    #Creation of column list to rename the columns in the dataframe
    columns = ["Date Created", "Number of Likes", "Source of Tweet", "Tweet"]
    
    #Creation of Dataframe
    tweets_df = pd.DataFrame(attributes_container, columns=columns)
except BaseException as e:
    print('Status Failed On,',str(e))


# In[ ]:





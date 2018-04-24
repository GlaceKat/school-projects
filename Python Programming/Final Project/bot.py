import praw
import os
import re

replied = []
comments = []

MAX_DEPTH = 10

def main():
    global found
    global comments
    global replied

    SUBREDDIT = 'pythonforengineers'
    KEYWORD = 'inconceivable'
    RESPONSE = 'r/princessbride'
    
    # Load already replied comment IDs
    if not os.path.isfile('replied.txt'):
        replied = []
    else:
        with open('replied.txt', 'r') as f:
            replied = f.read()
            replied = replied.split('\n')
            replied = list(filter(None, replied))

    reddit = praw.Reddit('bot1')
    subreddit = reddit.subreddit(SUBREDDIT)
    
    for submission in subreddit.new(limit = 10):
        for comment in submission.comments:
            try:
                check_replies(comment, KEYWORD, RESPONSE)
            except:
                pass # Ignore comment

    # Write matched comments to file
    with open('comments.txt', 'a+') as f:
        for comment in comments:
            f.write('{\n')
            f.write('   link: ' + comment['link'] + '\n')
            f.write('   comment: ' + comment['comment'] + '\n')
            f.write('}\n')
    with open('replied.txt', 'w') as f:
        for post_id in replied:
            f.write(post_id + '\n')

# Recursive function that checks a comment for a keyword and then checks all replies to that comment
def check_replies(comment, keyword, response, depth = 0):
    global found
    global comments
    global replied
    global MAX_DEPTH
    
    if comment.id not in replied and re.search(keyword, comment.body, re.IGNORECASE):
        comment.reply(response)
        replied += [comment.id]
        comments += [{'link': 'http://www.reddit.com/comments/' + comment.link_id.strip('t3_') + '/' + comment.id,
                      'comment': comment.body}]
    if depth < MAX_DEPTH:
        for reply in comment.replies:
            try:
                check_replies(reply, keyword, response, depth + 1)
            except:
                pass # Ignore reply

if __name__ == ('__main__'):
    main()

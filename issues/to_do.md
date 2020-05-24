
## to-do list

### Smart player decisions

In the current &beta; release, the players around the table limp into the pot and then check through until the showdown. We are looking
to create players who are able to make calculated based on the information available to them. The first step towards achieving this is 
collecting preliminary data regarding the value of each starting hand, as well as the probability of each hand landing.

### Data Collection

Collect the outcome of one million hands of poker so we can have accurate win percentages when choosing actions for each player.

The data we will process consists of the following items:

+ Pocket Cards,
+ Value of the winning hand.

From this we will produce an empirical histogram of hand values, used for counting our outs; win percentages of each pair of pocket cards, used when deciding whether you enter the pot.


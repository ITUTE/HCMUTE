''' NOTE: The following code is INCOMPLETE and CAN'T RUN. You need to add code here and there to make it work. '''

import gym
import numpy as np

import torch
import torch.nn as nn
import torch.optim as optim
import time
from collections import namedtuple

model = 1

if model == 1:
    HIDDEN_SIZE = 200
    BATCH_SIZE = 100
    PERCENTILE = 80

class Net(nn.Module):
    def __init__(self, obs_size, hidden_size, n_actions):
        super(Net, self).__init__()
        self.net = nn.Sequential(
            nn.Linear(obs_size, hidden_size),
            nn.ReLU(),
            nn.Linear(hidden_size, n_actions)
            )

    def forward(self, x):
        return self.net(x)

Episode = namedtuple('Episode', field_names = ['reward', 'steps'])
EpisodeStep = namedtuple('EpisodeStep', field_names = ['observation', 'action'])

def get_batches(env, net, batch_size):
    batch = []

    episode_reward = 0.0
    episode_steps = []

    obs = env.reset()
    sm = nn.Softmax(dim=1) # activation of output layer

    while True:
        obs_v = torch.FloatTensor([obs])


        act_probs_v = sm(net(obs_v))
        act_probs = act_probs_v.data.numpy()[0]
        action = np.random.choice(len(act_probs), p=act_probs)

        # MISSING CODE HERE
        next_obs, reward, is_done, _ = env.step(action)

        episode_reward += reward
        step = EpisodeStep(observation=obs, action=action)
        episode_steps.append(step)

        episode_reward += reward
        step = EpisodeStep(observation=obs, action=action)
        episode_steps.append(step)

        if is_done:
            # MISSING CODE HERE
            e=Episode(reward = episoda_reward, steps = episode_steps)

            batch.append(e)

            episode_reward = 0.0
            episode_steps = []
            next_obs = env.reset()

            if len(batch) == batch_size:
                yield batch
                batch = []

        obs = next_obs

def filter_batch(batch, percentile):
    rewards = list(map(lambda s: s.reward, batch))
    reward_bound = np.percentile(rewards, percentile)

    reward_mean = float(np.mean(rewards))

    train_obs = []
    train_act = []
    for reward, steps in batch:
        if reward < reward_bound:# MISSING CODE HERE:
            continue
        train_obs.extend(map(lambda step: step.observation, steps))
        train_act.extend(map(lambda step: step.action, steps))

    train_obs_v = torch.FloatTensor(train_obs)
    train_act_v = torch.LongTensor(train_act)
    return train_obs_v, train_act_v, reward_bound, reward_mean # MISSING CODE HERE

if __name__ == "__main__":
    # MISSING CODE HERE
    env = gym.make("LunarLander-v2")

    #train_mode = True
    train_mode = False
    if train_mode:
        obs_size = env.observation_space.shape[0] #input layer
        n_actions = env.action_space.n
        net = Net(obs_size, HIDDEN_SIZE, n_actions)

        objective = nn.CrossEntropyLoss()
        optimizer = optim.Adam(params=net.parameters(), lr=0.01)

        for iter_no, batch in enumerate(get_batches(env, net, BATCH_SIZE)):
            obs_v, acts_v, reward_b, reward_m = filter_batch(batch, PERCENTILE)# MISSING CODE HERE

            optimizer.zero_grad()
            action_scores_v = net(obs_v)
            loss_v = objective(action_scores_v, acts_v)

            loss_v.backward()
            optimizer.step()

            print("%d: loss=%.3f, reward_mean=%.1f, reward_bound=%.1f" % (
                iter_no, loss_v.item(), reward_m, reward_b))

            #if reward_m > 199: # for CartPole-v0
            if reward_m > 199: # for LunarLander-v2
                torch.save(net, "LunarLander-v2" + '_trained_net_' + str(HIDDEN_SIZE) + 'neurons.pt') # qNOTE: save ONLY 1 var/file
                print("Solved! Saved the model.")
                break

    else: # use the trained network
        env = gym.wrappers.Monitor(env, directory="solved_"+ "LunarLander-v2", force=True)
        # MISSING CODE HERE
        obs = env.reset()
        net = torch.load("LunarLander-v2" + '_trained_net_' + str(HIDDEN_SIZE) + 'neurons.pt')
        sm = nn.Softmax(dim=1)

        total_reward = 0

        while True:
            obs_v = torch.FloatTensor([obs])
            act_probs_v = sm(net(obs_v))
            act_probs = act_probs_v.data.numpy()[0]
            action = np.random.choice(len(act_probs), p=act_probs)

            # MISSING CODE HERE
            next_obs, reward, done, _ = env.step(action)

            env.render()
            time.sleep(0.01)

            total_reward += reward

            if done:
                input('press any key to exit')
                env.close()
                break

        print("Model %d (%d neurons). Total reward: %.2f" % (model, HIDDEN_SIZE, total_reward))


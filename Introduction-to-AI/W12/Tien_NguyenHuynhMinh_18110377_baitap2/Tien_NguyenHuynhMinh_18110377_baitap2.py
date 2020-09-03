import gym

#env = gym.make("Pendulum-v0")
#env = gym.make("CarRacing-v0")
env = gym.make("LunarLander-v2")
obs = env.reset()

while True:
    action = env.action_space.sample()
    obs, reward, done, info = env.step(action)
    env.render()

    if done:
        env.close()
        break

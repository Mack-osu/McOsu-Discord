# McOsu-Discord
Discord bot that reads live score data broadcasted from a fork of McOsu and displays it in Discord via slash commands. 

---

## Description
This bot listens for gameplay events sent over localhost from [McOsu-IPC](https://github.com/Mack-osu/McOsu-IPC), a fork of McOsu with HTTP POST support. Powered by [DPP](https://github.com/brainboxdotcc/DPP)<br>
It currently supports:
- Recent score statisticts through /McRecent

More features are planned for future updates.

![image failed to load](https://i.ibb.co/7dwRtq1s/image.png)

---

## Installation
No additional dependencies are required, the application is bundled with all necessary runtime files.

### Steps

1. [Download the latest release ZIP](https://github.com/Mack-osu/McOsu-Discord/releases)
2. Extract the ZIP
3. Fill out `config.txt` with your bot's token
4. Run `McOsu-Discord.exe`

---

### McOsu Setup

  This bot requires a a modified McOsu exe, which can be found [here](https://github.com/Mack-osu/McOsu-IPC/releases).
  Replace your existing McEngine.exe from your McOsu directory with the modified one.

  The bot and McOsu must be running on the same machine.
  
---

### To create a Discord Bot Application go to the [Discord Developer Portal](https://discord.com/developers/applications)
- Create a bot application by clicking `New Application`

  ![image failed to load](https://i.ibb.co/YFgFJ0pD/image.png)


- Check `Message Content Intent` found under the `Bot` tab
  
  ![image failed to load](https://i.ibb.co/57pBzxb/image.png)


- Under the `OAuth2` tab, create an invite link by selecting the `bot` scope and `Administator` Bot permission

  ![image failed to load](https://i.ibb.co/pjqXZ44r/image.png)


- Open the invite link in a new tab and add it to your desired server

  ![image failed to load](https://i.ibb.co/67PQ0RrP/image.png)


- Press `Reset Token` under the `Bot` tab

  ![image failed to load](https://i.ibb.co/qtysWHR/image.png)


- Copy your new bot token into `config.txt` ***⚠️ DO NOT SHARE THIS TOKEN WITH ANYONE ⚠️***

<br>

- Bot emojis must be uploaded manually, they can be found under the `Emojis` folder in your bot installation. 

  Upload them through the `Emojis` tab.

  ![image failed to load](https://i.ibb.co/NnQJ5fV4/image.png)

  Note: multiple emojis can be uploaded simultaneously

---

If you have any questions, send me a DM on discord @mackosu, I'd be happy to help!

# Pokemon Remake in C++

This project was inspired by the pong tutorial I had followed.  
That tutorial series taught me some basics for the Win32 API and I am now able to create a window and render simple images to the screen and move them with keyboard input.  
From there, I started to wonder how I could make simple sprites like in some of my favorite games and began to toy around with ideas to render them. 
This project, as of right now is very messy, and it used to be worse. This version here is what I submitted as a final project in my Japanese class, hence why the demo is in Japanese.  
The code itself is in English, and there is an English library in the game as I had started out making the game in English, it's just not used as I have not set it up to be used yet.  
The game is more like a demo, there's not much to do other than open the menu and interact with one npc, and all of this was rushed as I underestimated the amount of work required to make the sprites.  
Oh yeah, the sprites in this demo are really bad.  
I am still a novice when it comes to computer science and this game was my first real venture into making windows software. While I do know some basic data structures, I needed a refresher on pointers and classes in C++ before I started implementing useful data structures in the game.  
If you're curious as to what I am doing to learn these structures, please check out [this repo here](https://github.com/Marcus-Crump/CPP-Practice) to see that journey.  
All the images in this itteration of the project use really messy arrays that contain each animation frame, with each frame being a 2d array that contains the sprite pixel colors.  
This became too tedious to do longterm and I have since changed it by utilizing the code learned in [this repo](https://github.com/Marcus-Crump/BMP-Image-Tutorial)  
As of right now, you'll need to compile the game yourself to play the demo. This iteration also uses the number pad and its surrounding keys and will not work with other controls, but I will soon make a branch for the game in its current state. The reason I have not uploaded those changes is because I've not changed enough of the code to warrent pushing it to github. I need to rework all of the sprite creation with the current changes I have made, as well as clean up the main code to make it more modular so that it can be read and modified more easily.  
For now, please take a look at both the game as well as the messy code that runs it.

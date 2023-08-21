<!DOCTYPE html>
<html>
<head>
    <title>Snake and Ladder Game Documentation</title>
</head>
<body>

<h1>Snake and Ladder Game</h1>
<p>Welcome to the Snake and Ladder Game! This project implements a simple text-based version of the classic Snake and Ladder game in C.</p>

<h2>Table of Contents</h2>
<ul>
    <li><a href="#introduction">Introduction</a></li>
    <li><a href="#rules">Rules</a></li>
    <li><a href="#getting-started">Getting Started</a></li>
    <li><a href="#how-to-play">How to Play</a></li>
    <li><a href="#contributing">Contributing</a></li>
</ul>

<h2 id="introduction">Introduction</h2>
<p>This project provides a basic implementation of the Snake and Ladder game using the C programming language. The game is played in the terminal and allows multiple players to roll dice and move on the game board. The game board includes snakes and ladders that can affect the players' positions.</p>

<h2 id="rules">Rules</h2>
<ul>
    <li>The game is played on a 10x10 board with 100 squares.</li>
    <li>There are 10 players participating in the game.</li>
    <li>Players take turns rolling a dice and moving the corresponding number of squares.</li>
    <li>The objective is to reach the 100th square to win the game.</li>
    <li>Snakes and ladders are present on the board, affecting player positions.</li>
</ul>

<h2 id="getting-started">Getting Started</h2>
<p>To run the Snake and Ladder Game, follow these steps:</p>
<ol>
    <li>Make sure you have a C compiler installed on your system, such as GCC.</li>
    <li>Clone this repository to your local machine.</li>
    <li>Open a terminal and navigate to the project directory.</li>
    <li>Compile the code using the following command:</li>
</ol>
<pre><code>gcc -o snake_and_ladder snake_and_ladder.c</code></pre>
<p>Run the compiled executable:</p>
<pre><code>./snake_and_ladder</code></pre>

<h2 id="how-to-play">How to Play</h2>
<ol>
    <li>The game will display the initial positions of all players on the board.</li>
    <li>Players take turns rolling the dice by pressing Enter.</li>
    <li>The dice roll value is displayed, and the player's position is updated accordingly.</li>
    <li>Snakes and ladders are applied when a player lands on their respective squares.</li>
    <li>The game continues until a player reaches the 100th square, winning the game.</li>
</ol>

<h2 id="contributing">Contributing</h2>
<p>Contributions to this project are welcome! If you have ideas for improvements or bug fixes, feel free to fork this repository, make your changes, and submit a pull request.</p>
<p>Please ensure that your code follows the established coding style and conventions.</p>

</body>
</html>

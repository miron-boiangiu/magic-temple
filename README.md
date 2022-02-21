<div id="top"></div>

[![MIT License][license-shield]][license-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/miron-boiangiu/magic-temple">
    <img src="images/logo.png" alt="Logo" width="120" height="120">
  </a>

<h3 align="center">Magic temple</h3>

  <p align="center">
    A command-driven maze traveller, a password decoder and a 2-gram counter, all in one.
    <br />
    <br />
    <a href="https://github.com/miron-boiangiu/magic-temple/issues">Report Bug</a>
    ·
    <a href="https://github.com/miron-boiangiu/magic-temple/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

A 3-stage homework with multiple uses, able to draw the way followed through a maze, decode passwords, and to give information about the 2-grams found in a text.  
<br>
<a href="https://ocw.cs.pub.ro/courses/programare/teme_2021/tema2_2021_cbd">Assignment link.</a>

<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [C](http://www.open-std.org/jtc1/sc22/wg14/)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started



### Prerequisites

* make & gcc
  ```sh
  sudo apt-get install build-essential
  ```

### Compilation

1. Simply use the makefile included in order to compile the program.
   ```sh
   make
   ```
2. You can then run the program by running ./tema2.
   ```sh
   ./tema2
   ```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage
The program first asks which of the 3 functionalities the user wishes to access.  
  
1. Path drawer.  
2. Password decoder.  
3. 2-gram counter.  
  
#### Path drawer

The path drawer first asks for the array's size, then the moves the user follows through it, which follow a special format.  
The format is as follows:  
```sh
X → any digit  

aXXXX → the highest digit decides which way to move, as follows:  
first digit: right  
second digit: up  
third digit: left  
fourth digit: down  
  
bXXXX...XX → the X's form a number N. the last 2 X's form a number L.  
N palindrome, L prime: left  
N palindrome, L not prime: right  
N not palindrome, L prime: up  
N not palindrome, L not prime: down  

cNKXXXX..XX → N is the number of X's, which will form a number Q. A sum S will be computed by starting from the first digit of Q and summing the first K digits of Q, jumping over K digits each time.
S % 4 == 0: left
S % 4 == 1: up
S % 4 == 2: right
S % 4 == 3: down
```
  
#### Decoder

The user first inputs the type of encryption, then the key that was used for encryption, then the password to be decrypted.  
Types of encryption:  
- Caesar  
- Vigenere 
- Addition 
The addition decryption decrypts 2 numbers that were encrypted using the Caesar cypher then computes their sum. 

#### 2-gram counter

The user either types in the text or redirects the input from a file. The program then computes the number of unique 2-grams in the text and the number of apparitions for each one of them.  


#### Example of usage:

* []() Path drawer:  
	```sh
	Input:
	1
	4 4
	a1235 b121 c64123456
	Output:
	1 0 0 0
	2 3 4 0
	0 0 0 0
	0 0 0 0
	```
* []() Decoder:     
	```sh
	Input: 2
	caesar
	4
	abcdef1234
	Output: wxyzab7890
	```
	
* []() 2-gram counter:    
	```sh
	Input:
	3
	The weather is nice, the sun is nice too.
	The sun is yellow!
	Output:
	The weather 1
	weather is 1
	is nice 2
	nice the 1
	the sun 1
	sun is 2
	nice too 1
	too The 1
	The sun 1
	is yellow 1
	```
<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Boiangiu Victor-Miron - miron.boiangiu@gmail.com

Project Link: [https://github.com/miron-boiangiu/magic-temple](https://github.com/miron-boiangiu/magic-temple)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]:https://github.com/miron-boiangiu/magic-temple/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]:https://github.com/miron-boiangiu/magic-temple/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]:https://github.com/miron-boiangiu/magic-temple/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]:https://github.com/miron-boiangiu/magic-temple/issues
[license-shield]: https://img.shields.io/github/license/miron-boiangiu/magic-temple.svg?style=for-the-badge
[license-url]:https://github.com/miron-boiangiu/magic-temple/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png

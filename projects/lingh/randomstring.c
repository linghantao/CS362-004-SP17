Quiz 2 Explanation by Hantao Ling

I went about implementing the testme() function by first trying to understand exactly
what would cause the function to produce the error message. I figured out that the
error message would be produced after a two stage process. First, the random character
generator would have to produce 9 different characters in a specific order to advance
from state 0 to state 9. At this point, the random string generator would continue to
produce strings until the string "reset\0" was produced.

At this point, I broke down the problem into the random character stage and the random
string stage and checked if my assumptions were correct. To do this, I first created a
random character generator in inputChar() that returns a random character between ' '
and '~' in the ASCII table. I chose to limit the random characters between these two in
order to reduce number of trivial cases. All of the necessary characters for the testme()
function lie between the space and tilda characters. After running the testme() function
with this implementation of the inputChar() function, I saw that the testme() function
correctly advanced from state 0 to state 9.

Next, I implemented the inputString() function so that it directly returned "reset\0".
After running the testme() function again, I saw that it quickly produced the error
message. From this point, I altered the inputString() function so that it produced a
random string. I did this by allocating memory for a string of length 6 and set the last
character in the array to the null terminator. I then iterated through the first five
characters of the array and set each one to a random character from the set of lowercase
alphabet characters.

Finally, I compiled and ran the testme function and saw that it could produce the desired
error message (after waiting a few minutes).

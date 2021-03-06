 /**
 * @file 1041.Robot Bounded In Circle
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-09
 * @link https://leetcode.com/problems/robot-bounded-in-circle/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.
Example 3:

Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Constraints:

1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.
*/

//O(N) approach. SC: o(1)
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int horizontal = 0, vertical = 0;
        char dir = 'N';
        for(auto i : instructions){
            if(i == 'G'){
                vertical += dir == 'N'?1:0;
                vertical += dir == 'S'?(-1):0;
                horizontal += dir == 'E'?1:0;
                horizontal += dir == 'W'?(-1):0;
            }
            else{
                if(dir == 'N'){
                    dir = i == 'L'? 'W':'E';
                }
                else if(dir == 'S'){
                    dir = i == 'R'? 'W':'E';
                }
                else if(dir == 'W'){
                    dir = i == 'L'? 'S':'N';
                }
                else{
                    dir = i == 'R'? 'S':'N';
                }
            }
        }
        //cout<<horizontal<<" "<<vertical<<endl;
        return (horizontal == 0 and vertical == 0) or (dir != 'N');
    }
};
/*
"GLGLGGLGL"
*/
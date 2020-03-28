# **Finding Lane Lines on the Road** 
---

**Finding Lane Lines on the Road**

The goals / steps of this project are the following:
* Make a pipeline that finds lane lines on the road
* Reflect on your work in a written report


### Reflection

### 1.The Pipeline

My pipeline consisted of following steps:

1. Read the Image
2. Convert the Image from RGB to HLS using cv2.cvtColor
3. Isolate yellow and white from HLS image using cv2.inRange with threshold values as (15, 38, 115), (35, 204, 255) for yellow and (0, 200, 0) and (180, 255, 255) for white
4. Combine the yellow masked and white masked image into a single hsl image using cv2.bitwise_or
5. Combine the Original image and final HSL image using cv2.bitwise_and
6. Now Convert the color space filtered Combined HSL image into a gray scale image for further processing using the given helper function
7. Apply gaussian blur to smoothen the edges
8. Execute Canny Edge detection on smoothened gray image
9. Define the vertices and trace Region Of Interest to extract only the lines in that region
10. Perform a Hough Transform to find lanes within our region of interest
11. Draw the lines in the image as extrapolated full lane lines
12. Apply the pipeline for Images and Videos

#### Modifications done on draw_lines function:

1. Calling a function get_averaged_lines with input image and hough lines as input params
2. Defined the get_averaged_lines such that it does the following
* Seperate the left lane and right lane co-efficients by checking with their slope and x position
* find the averaged slope and intercept for left lane points using scipy.linregress
* using the slope and intercept calculate the full left straight line co-efficients (y=mx+b;m=slope,b=intercept)
* repeat the same for right lane points to get the co-efficients
* return the the lines (left lane and right lane)
3. draw the valid lines on the image using cv2.line

Finally, applied the same pipeline for Images and Videos and it worked in a decent manner. Thanks to Udacity.


### 2. Potential shortcomings with current pipeline

I have observed some problems with current implementation:
1. Straight lines does not look good on curved roads
2. In the challenge video, my code works in a decent way when I subclip it to first 5 seconds.
3. For first 5 seconds it is able to work a decent extent on curves also, but I am working on the logic to improve it further.



### 3. Possible improvements to current pipeline

Using the straight line equation y=mx+b might not go well on curved road videos.
So, the logic should be improved to suit on more such examples of challenge video.
I am working on the same.
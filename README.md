# vw-camper

Automatic lights for my Lego VW Camper Van 😎

<img width="300" src="https://sh-s7-live-s.legocdn.com/is/image/LEGO/10220?$main$">

## About

I wanted to add automatic lights to my Lego VW Camper Van.

### Lighting Kit

I got the lighting kit for my VW Campec from Light My Bricks. The kit was really easy to install.
The lights are manually tuned on with a battery pack that sits on the back bench seat.

<img width="300" src="https://cdn-images-1.medium.com/max/1600/1*09DyZCRjF8yI6dniAK3qvg.jpeg">

## Circuit

The lighting control circuit was my own creation. I prototyped a simple Aruduino project which reads
the current sunlight level from outside using an LDR and pull down resistor.

<img width="300" src="http://i.imgur.com/zj6GY50.png">

The Arduino board will serve as a power supply to the lights, so I did away with the battery pack
that's provided with the lighting kit.

## Program

If the sunlight level is within a predefined range, the program will turn the lights on in the camper
van. There's also a time constraint: the lights can only be turned on between 18:00 and 22:00 as
I don't want to waste energy lighting the camper when I'm not there to see it.


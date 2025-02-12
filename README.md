# Crime Data - OOP Final Project
> A C++ program that goal is to compare crimes and criminal incidents reported in three cities: New York, Los Angeles, and San Francisco. It reads and clears CSV files, creates new ones, and is accompanied by visualizations prepared in Microsoft PowerBI.


## Table of Contents
* [General Info](#general-information)
* [Features](#features)
* [Technical Description](#technical-description)


## General Information
- I embarked on the project to satisfy the subject's passing criteria.
 
- CSV files processed were downloaded from the data.gov website. They lack full cohesiveness, as the LA file presents incidents of crime, NY is a breakdown of every arrest effected in NYC, and SF's dataset includes incident reports.
However, it was necessary to meet the project requirement of 3 files exceeding the size of 0.5MB and these were the most interesting and related datasets I could find. 

- The program reads three CSV files separately, skips unnecessary data in the process, stores them in created class objects, removes rows with empty fields, sorts the data, prints the number of incidents by category (also possibleby date), and writes cleared and sorted data to another CSV file.

- Visuals utilize cleared CSV files and make use of latitude and longitude data included in them. There you can see the exact localization of every crime/incident included, and also filter it by date, category, or age.

- As two of the files were too large to upload, I leave two links to download them here: [San Francisco](https://catalog.data.gov/dataset/police-department-incident-reports-2018-to-present) [Los Angeles](https://catalog.data.gov/dataset/crime-data-from-2020-to-present)

### Language elements introduced in the course included in the project
- classes
- inheritance
- constructors
- friend methods
- function templates
- reading a CSV file
- writing to a file
- sorting a CSV file
- error handling
- for-each loops
- vectors
- iterators

## Features


- Number of incidents by category
<img width="949" alt="sc1" src="https://user-images.githubusercontent.com/109167046/212193686-42f9027c-e901-4909-9d2f-3e0552029e9c.png">


- Los Angeles visual
<img width="960" alt="sc22" src="https://user-images.githubusercontent.com/109167046/212193953-737e27d5-f800-4fd4-9e0f-ecccf5eebe29.png">


- New York visual
<img width="960" alt="sc3" src="https://user-images.githubusercontent.com/109167046/212193958-bc2a9c4c-9d39-43c9-bd64-c6dc14408b07.png">


- Expected output for the LA file
<img width="960" alt="sc4" src="https://user-images.githubusercontent.com/109167046/212193963-0702963c-7c87-4b03-977c-c601a605acb0.png">


## Technical Description

### Language
- C++ 14 

### Libraries used
- iostream
- fstream
- string
- vector
- sstream
- algorithm
- map

### Integrated Development Environment
- Visual Studio 2019



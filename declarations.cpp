#include "definitions.h"

//NEW YORK

//one-parameter constructor to open the file and read the data
CSVFileNY::CSVFileNY(std::string filename) {
  //opening the file
  std::ifstream file(filename);

  //error handling
  if(!file.is_open()) {
    std::cerr << "ERROR: unable to open file '" << filename << "'" << std::endl;
    exit(0); //exiting if the file is invalid
  }

  //row to store each line of the file
  CSVRowNY row;
  while(file >> row) {
    //adding the row to the rows vector
    rows.push_back(row);
  }
};

//overloading the stream operator to read a row from a CSV file
std::istream& operator>>(std::istream& str, CSVRowNY& data) {
  data.clearRow(); //clearing a row from the old content
  std::string line; 
  std::string field;
  getline(str, line);

  //if it's the header we return
  if(line.find("ARREST_KEY,") != std::string::npos)
  {
    return str;
  }
  std::stringstream l(line); //initializing stringstream object to use it in the next getline
  int i = 0; 
  while(getline(l, field, ','))
  {
    //handling commas in one field, doing it before checking field index, so that it doesnt mix indexes up
    if(!field.empty() && field.front() == '"')
    {
      std::string restOfCell; //ancillary variable
      while(field.back() != '"') //looking for a field-ending parenthesis
      {
        getline(l, restOfCell, ','); //adding content until the next comma is find
        field += ',' + restOfCell; 
      }
      field = field.substr(1, field.size() - 2); //removing quotation marks and a comma at the end 
    }

    //after dealing with commas we can add the field to the vector
    if(i == 1 || i == 5 || i == 11 || i == 12 || i == 16 || i == 17)
    {
      //no need to look for data from 2022, csv file already satisfies the condition
      data.fields.push_back(field);
    }
    i++;
  }
  return str;
}

//clear a row
void CSVRowNY::clearRow()
{
  this->fields.clear();
}



//LOS ANGELES

//one-parameter constructor to open the file and read the data
CSVFileLA::CSVFileLA(std::string filename) {
  //opening the file
  std::ifstream file(filename);

  //error handling
  if(!file.is_open()) {
    std::cerr << "ERROR: unable to open file '" << filename << "'" << std::endl;
    exit(0);
  }
  CSVRowLA row;
  while(file >> row) {
    if(row.fields.size())
    {
      rows.push_back(row);
    }
  }
}

std::istream& operator>>(std::istream& str, CSVRowLA& data) {
  data.clearRow();
  std::string line;
  std::string field;
  getline(str, line);
  std::stringstream l(line);
  int i = 0;
  while(getline(l, field, ','))
  {
    //removing data from earlier than 2022
    if(i == 2 && field[9] != '2')
    {// 11/16/2021  12:00:00 AM - 10th character determines the year
      //data.fields.clear();
      data.fields.clear();
      break; //going to the next row
    }
    if(!field.empty() && field.front() == '"')
    {
      std::string restOfCell;
      while(field.back() != '"')
      {
        getline(l, restOfCell, ',');
        field += ',' + restOfCell;
      }
      field = field.substr(1, field.size() - 2);
    }
    //2-date, 7-age, 8-sex, 11-charge group, 18-latitude, 19-longtitude
    if(i == 2 || i == 7 || i == 8 || i == 11 || i == 18 || i == 19)
    {
      data.fields.push_back(field);
    }
    i++;
  }
  return str;
}


//SAN FRANCISCO

//one-parameter constructor to open the file and read the data
CSVFileSF::CSVFileSF(std::string filename) {
  //opening the file
  std::ifstream file(filename);

  //error handling
  if(!file.is_open()) {
    std::cerr << "ERROR: unable to open file '" << filename << "'" << std::endl;
    exit(0);
  }

  CSVRowSF row;
  while(file >> row) {
    if(row.fields.size())
    {
      rows.push_back(row);
    }
  }
}

std::istream& operator>>(std::istream& str, CSVRowSF& data) {
  data.clearRow();
  std::string line;
  std::string field;
  getline(str, line);
  std::stringstream l(line);
  int i = 0;
  while(getline(l, field, ','))
  {
    //removing data from earlier than 2022
    if(i == 3 && field != "2022")
    {
      data.fields.clear();
      break;
    }
    if(!field.empty() && field.front() == '"')
    {
      std::string restOfCell;
      while(field.back() != '"')
      {
        getline(l, restOfCell, ',');
        field += ',' + restOfCell;
      }
      field = field.substr(1, field.size() - 2);
    }
    //1 - date, 14 - incident category, 15 - incident subcategory, 16 - description, 23 - latitude, 24 - longtitude
    if(i == 1 || i == 14 || i == 15 || i == 16 || i == 23 || i == 24)
    {
      data.fields.push_back(field);
    }
    i++;
  }
  return str;
}






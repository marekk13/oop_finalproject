#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

//NEW YORK

//class to represent a row in a CSV file andsuited to extract 
//certain columns from NYPD_Arrest_Data__Year_to_Date_.csv and to skip unnecessary data
class CSVRowNY
{
public:
  //vector of strings, each string represents a field 
  std::vector<std::string> fields;

  //operator used to read a row
  friend std::istream& operator>>(std::istream& str, CSVRowNY& data);

  //method to clear a row
  void clearRow();
};


//class to represent a CSV file
class CSVFileNY {
public:
  //representing a file as a vector of rows
  std::vector<CSVRowNY> rows;

  //default constructor neccessary for inheritance
  //a derived-class constructor always invokes a constructor for the base class
  CSVFileNY() {};

  //one-parameter constructor to open the file and read the data
  CSVFileNY(std::string filename);

  //template structure to determine whether a row is fit for deletion
  //used in removeEmpty method
  template <typename T>
  struct check_empty
  {
    //operator returns true if a row has at least one empty or "(null)" field
    bool operator()(const T& row) const
    {
      if(!row.fields.size())
      {
        return true;
      }
      for(const std::string& field : row.fields)
      {
        if(field.empty() || field == "(null)")
        {
          return true;
        }
      }
      return false;
    }
  };

  //according to The C++ standard library: a tutorial and handbook 
  //"The only portable way of using templates at the moment is to implement them in header files"
  template <typename T>
  bool removeEmpty(std::vector<T>& rows) //method to remove rows with empty fields
  {
    if(rows.empty())
    {
      std::cerr << "ERROR: The file is empty" << std::endl;
      return false;
    }
    rows.erase(std::remove_if(rows.begin(), rows.end(), check_empty<T>()), rows.end());
    return true;
  }


  //sort by field
  template <typename T>
  bool CSVsort(int field, std::vector<T>& rows)
  {
    if(field < 0 || field > 4)
    {
      std::cerr << "ERROR: Field argument must be between 0 and 4" << std::endl;
      return false;
    }

    sort(rows.begin(), rows.end(), [&](const T& a, const T& b) {return a.fields[field] < b.fields[field]; });
    return true;
  }

  //create a cleared csv file
  template <typename T>
  bool clearedCSV(const std::string& filename, const std::vector<T>& rows)
  {
    //creating an output stream
    std::ofstream fout{ filename };

    //error handling
    if(!fout.is_open())
    {
      return false;
    }

    //iterating over each row
    for(const T& row : rows)
    {
      //creating a vector iterator
      std::vector<std::string>::const_iterator field = row.fields.begin();
      while(field != row.fields.end())
      {
        fout << '\"' << *field << '\"';
        ++field;
        //not adding a comma after the last field in a line
        if(field != row.fields.end())
        {
          fout << ',';
        }
      }
      //new line after a row
      fout << '\n';
    }
    return true;
  }

  //first field in a map is an entity (for example a single day) for which count is calculated
  //second one is the count
  //for example if we pass 0 we get number of incidents for every day (index 0 in CSVRow vector represents date)
  template <typename T>
  std::map<std::string, int> countRowsBy(const int column, const std::vector<T>& rows) {
    std::map<std::string, int> dateCounts; //map declaration
    for(const T& row : rows) {
      if(row.fields.size() > column) {
        dateCounts[row.fields[column]]++; //increase the count
      }
    }

    //erasing CSV header which has always value 1, we asses that other fields dont have such value
    for(auto it = dateCounts.begin(); it != dateCounts.end(); ) {
      if(it->second == 1) {
        it = dateCounts.erase(it);
      }
      else {
        ++it;
      }
    }
    return dateCounts;
  }

  template <typename T>
  void printCounts(const int column, const std::vector<T>& rows) {
    std::map<std::string, int> dateCounts = countRowsBy<T>(column, rows);
    for(const auto& dateCount : dateCounts) {
      auto s = dateCount.first;
      //  s = s.substr(0, s.find(" "));//there is hour after date in LA file, so we exlude it for printing
      std::cout << s << ": " << dateCount.second << std::endl;

    }
  }
};


//LOS ANGELES

class CSVRowLA : public CSVRowNY {
public:
  //operator used to read a row
  friend std::istream& operator>>(std::istream& str, CSVRowLA& data);
};


class CSVFileLA : public CSVFileNY {
public:
  //representing a file as a vector of rows
  std::vector<CSVRowLA> rows;

  //one-parameter constructor to open the file and read the data
  CSVFileLA(std::string filename);
};



//SAN FRANCISCO

class CSVRowSF : public CSVRowNY {
public:
  //operator used to read a row
  friend std::istream& operator>>(std::istream& str, CSVRowSF& data);
};

class CSVFileSF : public CSVFileNY {
public:
  //representing a file as a vector of rows
  std::vector<CSVRowSF> rows;

  //one-parameter constructor to open the file and read the datas
  CSVFileSF(std::string filename);
};

#endif


// crimedata.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "definitions.h"

int main()
{
  /*
  //first, we load the CSV file into our class object and skip redundant data in the process
                     //date, crime category, age group, sex, latitude, longitude
  CSVFileNY file1("NYPD_Arrest_Data__Year_to_Date_.csv"); //new york
  std::cout << "NEW YORK\n\n";

  //then, we remove rows with empty fields
  if(file1.removeEmpty(file1.rows))
  {
    std::cout << "File with data from NY was cleared from rows with empty fields" << std::endl;
  }

  //sorting
  auto i = 0;
  if(file1.CSVsort(0, file1.rows))
  {
    std::cout << "File with data from NY was sorted by row number " << i + 1 << std::endl ;
  }

  //printing number of incidents by a field (in this case crime category, could be date)
  std::cout << "\nCrime category\tNumber of incidents\n";
  file1.printCounts(1, file1.rows);

  //saving cleared and sorted data in a new CSV
  if(file1.clearedCSV("NY.csv", file1.rows))
  {
    std::cout << "\nNew CSV was created\n\n\n" << std::endl;
  }
  

  */
  
                  //date, age, sex, charge group, latitude, longitude
  CSVFileLA file2("Arrest_Data_from_2020_to_Present.csv"); //los angeles
  std::cout << "LOS ANGELES\n\n";
  std::cout << "File with data from LA was loaded" << std::endl;

  if(file2.removeEmpty(file2.rows))
  {
    std::cout << "File with data from LA was cleared from empty rows" << std::endl;
  }
  auto i = 0;
  if(file2.CSVsort(i, file2.rows))
  {
    std::cout << "File with data from LA was sorted by row number "<< i+1 << std::endl;
  }

  std::cout << "\nCrime category\tNumber of incidents\n";
  file2.printCounts(3, file2.rows);

  if(file2.clearedCSV("LA.csv", file2.rows))
  {
    std::cout << "\nNew CSV was created\n\n\n" << std::endl;
  }
 
 
  
  /*
                  //date, incident category, incident subcategory, description, latitude, longitude
  CSVFileSF file3("Police_Department_Incident_Reports__2018_to_Present.csv"); //san francisco
  std::cout << "SAN FRANCISCO\n\n";
  std::cout << "File with data from SF was loaded" << std::endl;

  if(file3.removeEmpty(file3.rows))
  {
    std::cout << "File with data from SF was cleared from empty rows" << std::endl;
  }

  if(file3.CSVsort(i, file3.rows))
  {
    std::cout << "File with data from SF was sorted by row number " << i + 1 << std::endl;
  }

  std::cout << "\nCrime category\tNumber of incidents\n";
  file3.printCounts(1, file3.rows);

  if(file3.clearedCSV("SF.csv", file3.rows))
  {
    std::cout << "\nNew CSV was created\n\n\n" << std::endl;
  }
 */
}






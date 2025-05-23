// Chapter 9, Programming Challenge 2: Test Scores #1
// Your Name: Catherine Yousefi
// Date: 3.20.2025
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
// Define two functions below named sort and average with one of the parameters being
// the pointer to the test scores array
void sort(double*, int);
double average(double*, int);


int main()
{
   int numTestScores = 0;           // The number of test scores
   double *testScorePtr = nullptr;  // To point to an array
   double testAverage = 0;          // The test score average

   // Get the number of test scores.
   cout << "\nHow many test scores will you enter? ";
   cin >> numTestScores;
   
   // Validate the input.
   while (numTestScores < 0)
   {
      cout << "The number cannot be negative.\n";
      cout << "Enter another number: ";
      cin >> numTestScores;
   }

   // Allocate an array to hold the test scores.
   testScorePtr = new double[numTestScores];

   // Fill the array with test scores.
   for (int i = 0; i < numTestScores; i++)
   {
      // Get a test score.
      cout << "Enter test score "
           << (i + 1) << ": ";
      cin >> testScorePtr[i];
      
      // Validate the input.
      while (testScorePtr[i] < 0)  
      {
         cout << "Negative scores are not allowed.\n";
         cout << "Enter another score for this test: ";
         cin >> testScorePtr[i];
      }
   }

   // Sort the test scores.
   //call the sort functions with appropriate arguments


   // Get the average of the test scores.
   testAverage = average(testScorePtr, numTestScores);

   // Display the resulting data.
   cout << "\nThe test scores in ascending "
        << "order, and their average, are:\n\n";
   cout << " Score" << endl;
   cout << " -----" << endl;
   
   for (int j = 0; j < numTestScores; j++)
   {
      cout << "\n" << fixed << setprecision(2) 
           << setw(6) << testScorePtr[j];
   }

   cout << "\n\nAverage score:  " << setprecision(2)
        << fixed << testAverage << endl << endl;

   // Free the dynamically-allocated memory.
   delete [] testScorePtr;
   testScorePtr = nullptr;
   
   return 0;
}

// ********************************************************
// The sort function performs a selection sort on the     *
// array pointed to by the score parameter into ascending *
// order. The size parameter holds the number of elements.*
// ********************************************************
// Code the sort function here
void sort(double* scores, int size)
{
   for (int i = 0; i < size - 1; i++)
   {
      int minIndex = i;
      for (int j = i + 1; j < size; j++)
      {
         if (scores[j] < scores[minIndex])
         {
            minIndex = j;
         }
      }
      // Swap elements
      double temp = scores[i];
      scores[i] = scores[minIndex];
      scores[minIndex] = temp;
   }
}

// ********************************************************
// The average function calculates and returns the        *
// average of the values stored in the array passed into  *
// the scores parameter. The parameter numScores holds    *
// the number of elements in the array.                   *
// ********************************************************
// Code the average function here
double average(double* scores, int numScores)
{
   double total = 0.0;
   for (int i = 0; i < numScores; i++)
   {
      total += scores[i];
   }
   return total / numScores;
}


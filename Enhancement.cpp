#include <fstream>

class Enhancement
{
private:
	int numRows, numCols;
	int minVal, maxVal;
	int maskRows, maskCols;
	int maskMin, maskMax;
	int newMin, newMax;
	int thrVal;				// from argv[3]
	int **mirrorFmAry;		// [numRows+2] × [numCols+2]
	int **avgAry;			// [numRows+2] × [numCols+2]
	int **medianAry;		// [numRows+2] × [numCols+2]
	int **gaussAry;			// [numRows+2] × [numCols+2]
	int **thrAry;			// [numRows+2] × [numCols+2]
	int **mask2DAry;		// [maskRows]  ×  [maskCols]
	int mask1DAry[9];		// holds the 9 pixels of the mask, for easy convolution computation
	int maskWeight;			// the total value of the mask; can be computed during loadMask
	int neighbor1DAry[9];	// holds a pixel [i][j]'s 3×3 neighbors, for easy computation
public:
	Enhancement();
	void binThreshold(int **, std::ofstream &);						//
	void prettyPrint(int **, std::ofstream &logFile);				// print the int** to logFile
	void mirrorFraming(int **, int **, std::ofstream &logFile);		// use `mirrorFmAry`
	void loadImage(std::ifstream &inFile, std::ofstream &logFile);	// load into `mirrorFmAry`
	~Enhancement();
};

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
	void binThreshold(int **inArray, std::ofstream &);		//
	void prettyPrint(int **, std::ofstream &);				// print the int** to ofstream
	void mirrorFraming(std::ofstream &);					// use `mirrorFmAry`: [1][]->[0][], [numRows+1][]->[numRows][]; [][1]->[0][], [][numCols+1]->[][numCols]
	void loadImage(std::ifstream &, std::ofstream &);		// load ifstream into `mirrorFmAry` starting at [1][1]
	int loadMask(std::ifstream &, std::ofstream &);			// load ifstream (the maskFile) onto mask2DAry and return maskWeight
	void loadMask2Dto1D(std::ofstream &);					//

	~Enhancement();
};

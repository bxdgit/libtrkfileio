#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "FiberData.h"
using namespace std;

int main()
{
    /// input & output filename
    string strInputFilePath  = "C:/input/input.trk";
    string strOutputFilePath = "D:/output.trk";

    /// create reader and open file
    FiberData fData;
    if( !fData.open(strInputFilePath) )
        return EXIT_FAILURE;

    /// create writer and create an empty new file

    if( !fData.writer(strOutputFilePath) )
        return EXIT_FAILURE;

    /// random sampling (0.1%)
    vector<float> cTrk;
    size_t iTotalTrackNum = fData.getTotalTrkNum();  /// total number of tracks in input file
    srand((unsigned int)(time(nullptr)));                           /// random seed
    for(size_t i = 0; i < iTotalTrackNum; i++)
    {
       /* if( rand() % 1000 < 998 )   /// 0.1% random sampling
            continue;*/
        cTrk.clear();
		fData.readTrack(i, cTrk); /// read one track from input
		fData.appendTrack(cTrk);  /// write it back to output
    }

    /// close input and output file
	fData.close();

    cout << "Finished" << endl;
    return EXIT_SUCCESS;
}


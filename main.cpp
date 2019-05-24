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
    FiberData cReader;
	cReader.setFilepath(strInputFilePath);
    if( !cReader.open() )
        return EXIT_FAILURE;

    /// create writer and create an empty new file
	FiberData cWriter;
	cWriter.setWFilepath(strOutputFilePath);
    if( !cWriter.create() )
        return EXIT_FAILURE;

    /// random sampling (0.1%)
    vector<float> cTrk;
    size_t iTotalTrackNum = cReader.getTotalTrkNum();  /// total number of tracks in input file
    srand((unsigned int)(time(nullptr)));                           /// random seed
    for(size_t i = 0; i < iTotalTrackNum; i++)
    {
       /* if( rand() % 1000 < 998 )   /// 0.1% random sampling
            continue;*/
        cTrk.clear();
        cReader.readTrack(i, cTrk); /// read one track from input
        cWriter.appendTrack(cTrk);  /// write it back to output
    }

    /// close input and output file
    cWriter.Wclose();
    cReader.close();

    cout << "Finished" << endl;
    return EXIT_SUCCESS;
}


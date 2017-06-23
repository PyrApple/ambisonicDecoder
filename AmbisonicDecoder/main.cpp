//
//  main.cpp
//  AmbisonicDecoder
//
//  Created by David Poirier-Quinot on 17/06/2017.
//  Copyright © 2017 ICL. All rights reserved.
//

#include <iostream>
#include "ambisonicDecoder.hpp"

int main( int argc, const char * argv[] ) {
    
    unsigned order = 1;
    unsigned nCh = pow(order + 1, 2);
    bool useEpad = false;
    
    std::vector<float> gains;
    gains.resize(nCh);

    AmbisonicDecoder ambisonicDecoder;

    Eigen::MatrixXf ambiGains;
    Eigen::MatrixXf spkAzimElev (2, 6);
    
    spkAzimElev <<
    0, 90, 180, 270, 0, 0,
    0, 0, 0, 0, 90, -90;
    
    std::cout << "speaker config (azim, elev): \n" << spkAzimElev << "\n";

    ambiGains = ambisonicDecoder.getDecodingMatrix( spkAzimElev, order, useEpad );
    std::cout << "decoding matrix: \n" << ambiGains << std::endl;
        
    return 0;
}

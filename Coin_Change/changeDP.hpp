//
//  changeDP.hpp
//  Project2
//
//  Created by Patrick Mullaney on 4/27/17.
//  Copyright © 2017 Patrick Mullaney. All rights reserved.
//

#ifndef changeDP_hpp
#define changeDP_hpp

#include <stdio.h>
#include <vector>
#include "structCoins.h"

// Returns struct containing minimum number of coins and denomination of coins.
struct coins changeDP(vector<int> coin, int amount, struct coins change);

#endif /* changeDP_hpp */

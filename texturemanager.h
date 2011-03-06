/*
 *  texturemanager.h
 *  ztower-ng
 *
 *  Created by gm on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#import <string>
#import <map>
#import "zImage.h"

using namespace std;

class textureManager {
	public:
	textureManager();
	zImage* texture(char* name);
	void loadAll();
	private:
	map<string, zImage*> textures;
};

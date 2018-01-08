#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void drawStructure(float x, float y, int curDepth);
    void drawCircleAndLines(int curDepth);
    bool save;
};

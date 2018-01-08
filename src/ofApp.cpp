//  Author: Amay Kataria
//  Date: 09/20/2017
//  Description: Generative recursive art.

// Extend this program to read these inputs from Touch Osc. Map these paramters to the right slider values.

#include "ofApp.h"

int theta = 60;
int lineLength = 50;
int maxDepth = 5;
int circleRadius = 15;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(ofColor::white);
  ofSetCircleResolution(100);
  
  save = true;
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

void ofApp::drawCircleAndLines(int curDepth) {
  // Base condition for recursion.
  if (curDepth > maxDepth) {
    return;
  }
  
  // Increment current depth for the subsequent recursive calls.
  curDepth = curDepth + 1;
  
  // Draw circle at the translated center coordinates.
  ofNoFill();
  ofSetColor(ofColor::black);
  ofDrawCircle(0, 0, circleRadius);
  
  // Draw inner lines.
  for (int i = 0; i < 360; i = i + theta) {
    ofPushMatrix();
      ofRotateZDeg(i);
      ofSetColor(153, 153, 153);
      ofSetLineWidth(2.0f);
      ofDrawLine(0, 0, lineLength, lineLength);
      drawStructure(lineLength, lineLength, curDepth);
    ofPopMatrix();
  }
}

// Draws the core structure at (x, y).
void ofApp::drawStructure(float x, float y, int curDepth) {
  if (curDepth < maxDepth) {
    ofPushMatrix();
      ofTranslate(x, y);
      drawCircleAndLines(curDepth);
    ofPopMatrix();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  if (save) {
    ofBeginSaveScreenAsPDF("test.pdf");
  }
  
  ofPushMatrix();
    // Pass curDepth = 0 to let Draw loop create this structure infinitely.
    drawStructure(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    ofScale(0.5, 0.5);
  ofPopMatrix();
  
  if (save) {
    ofEndSaveScreenAsPDF();
    save = false;
  }
}

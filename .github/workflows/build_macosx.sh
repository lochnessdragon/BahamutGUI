name: Build Mac OSX

on: [push]

env:
  BUILD_XCWORKSPACE_FILE: ./BahamutGUI.xcworkspace

jobs:
  build:
    runs-on: macos-latest
    
    steps:
    - uses: actions/checkout@v2
    
    - name: Setup Xcode Workspace
      working-directory: ${{env.GITHUB_WORKSPACE}}
      run: ./tools/premake/premake5 xcode4
      
    - name: Build with xcode
      working-directory: ${{env.GITHUB_WORKSPACE}}
      run: xcodebuild -workspace ${{env.BUILD_XCWORKSPACE_FILE}}

# 06 Debugging

## Assignment spec

Please debug and run unit tests on `ValidateUserInputWithinIntegerRange()` which is declared in `src/class_roster.h` and implemented in `src/class_roster-lib.cpp`. 
- (5 points, manually graded) Please take a screenshot of debugging while in *launched and paused* at some breakpoint and upload a screenshot to BlackBoard assignments. 
- (5 points, autograded on push to sync) This function contains two bugs. Please identify them and make sure unit tests pass. Unit tests can be executed with `Test with make and Catch2` task. 

## Steps

- Please accept `06` assignment from *BlackBoard* as usual. Visit generated repo `OU-CTCH1330/06-debugging-yourGitHubId` on GitHub, open Codespace.
- Bulk of the code now is in `src/class_roster_lib.cpp` file, including `ValidateUserInputWithinIntegerRange()` function which contains two bugs. Please examine this function, you may be able to identify two bugs even without debugging. 
- Please build the project. This can be done for example by running `Terminal > RunBuildTask`. Every time you make a code change please make sure to (re)build the project. Debugging runs off executable `bin/class_roster` and `src/*.cpp` source files and two need to be in sync for debugging to work. 
<br />Alternative: `make all` from bash console will do the same. 
- Put a break point somewhere (preferably early on) in `ValidateUserInputWithinIntegerRange()` function. This can be done by having cursor on respective line and `Run > ToggleBreakPoint`. *Red dot* should appear. Breakpoint should be on a statement line, a step in execution of the program. For example, can't break on empty line.
<br /> Alternative: The same can be done by clicking mouse on the left margin of the desired line
<br /> Alternative: F9 keyboard.
- Start debugging by `Run > StartDebugging`. Keep an eye on `Terminal` console (you may have to tab back to it). Provide user input as requested to navigate the app to target function `ValidateUserInputWithinIntegerRange()`. 
  - above requires going into student deleting operation and then submitting (valid or invalid) index of student-to-be-deleted.
- Once app enters execution in `ValidateUserInputWithinIntegerRange()` function your breakpoint should kick in. You should see debugging panel (_Step/Over/In/Out_ and such) popping up on the screen. 
- This would be a good time to take a screenshot and save for uploading to *BlackBoard*.
- Examine `Variables` panel (top left). Make sure values of various variables make sense. 
- By using debug panel "step through" the function. Monitor how execution enters or skips various blocks and branches of code. Compare this against values of various variables, decide if execution path is consistent with expected behavior. Try to identify bugs.
- You may have to recycle these steps several times, deleting yet another student, trying valid and invalid inputs for student to be deleted. Keep in mind, at times program will be waiting for various user inputs, which you should submit through `Terminal` console, as you would for a regular running program. 
- Once you have identified bugs, please exit debugging (`Stop` on debug panel). In general, be always aware whether program is running and debugging, or not. If running, is it in break mode, executing, or waiting for input. 
- Fix bugs by editing `ValidateUserInputWithinIntegerRange()`
- Run `Test with make and Catch2` task, make sure it reports 
<br /><span style='color: #8ae234'>All tests passed</span>
- Stage, commit and sync your code, make sure autograder accepts submission in GitHub actions. 
- If something goes wrong, please reach out early on, do NOT struggle. PR associated with this repo is a good place for Q&A. Please remember to commit and sync your code, I can only see your code once committed to GitHub repo (can't see code in your CodeSpace). Grade doesn't care about erroneous code, points will be confirmed all the same once correct code is pushed. 

## General tips 

These tips are general, not specific to current assignment.

- Each repo expects a dedicated Codespace
- Please try not to spam Codespaces. Old instances are available at  [https://github.com/codespaces](https://github.com/codespaces) and they load faster
- Consider cleaning up CodeSpaces for past assignments. They can be deleted (if running, stopped and deleted) by clicking `...` next to them 
- At any point it helps to build and run app. Once compiled, executable can be launched with `bin/class_roster`. Knowing application helps make sense of code and understand what each function is meant to do. 
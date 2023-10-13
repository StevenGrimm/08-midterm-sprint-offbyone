#include <iostream>
#include <limits>
#include <tuple>
#include "class_roster.h" 

namespace ctch1330
{
	void RenderMainMenu(vector<string> menu) 
	{	
		if ( menu.empty() )
		{
			throw runtime_error( "Database error, could not retrieve Menu functionality data" );
		}
		
		cout << endl << "Main menu:" << endl << endl;

		for (string menu_item : menu)
		{
			cout << menu_item << endl;
		}


		return;
	}




	void DisplayRoster(vector<string> roster)
	{
		int roster_size = roster.size();

		cout << endl << "Class roster:" << endl << endl;

		for (int i = 0; i < roster_size; i++)
		{
			cout << i+1 << ". " << roster[i] << endl;
		}
		WaitForUser();	
		return;
	}

	vector<string> AddStudent(vector<string> roster, int max_class_size)
	{
		if ( max_class_size < 0)
		{
			throw runtime_error( "Can't have negative class cap" );
		}
		
		string new_entry = "";

		if (roster.size() == max_class_size)
		{
			cout << endl << "Class is full, apologies, no more student can be added" << endl;
			WaitForUser();
		}
		else
		{
			cout << endl << "Please enter student information" << endl;

			cin >> new_entry;
			
			roster.push_back(new_entry); 
			cout << "Student information has been saved." << endl;
			WaitForUser();
		}
		return roster;
	}

	vector<string> DeleteStudent(vector<string> roster, vector<string> grade) 
	{
			cout << endl << "Please enter index of student to be deleted" << endl;
			int index_of_student_selected_for_deletion = GetUserInputWithinIntegerRange(1, roster.size()+1);
			
			roster.erase( roster.begin() + index_of_student_selected_for_deletion - 1 );
			grade.erase( grade.begin() + index_of_student_selected_for_deletion - 1 );//now deletes grades along with student
			cout << endl << "Student information deleted, please press any character to continue" << endl;	
			WaitForUser();
			return roster;
	}
	// new functionality to display selected students grade
void DisplayGrade(vector<string> roster, vector<string> grade)
	{
			cout << endl << "Please enter index of student to see their grade" << endl;
			int index_of_student_selected_for_grade_display = GetUserInputWithinIntegerRange(1, grade.size()+1);

			cout << endl << roster[index_of_student_selected_for_grade_display - 1 ] << " " << grade [index_of_student_selected_for_grade_display - 1] << endl;
			WaitForUser();
			return;
	}
	void WaitForUser()
	{
		cout << endl << "Please press enter to continue..." << endl;
		cin.get();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n' );	
	}

	void PrintInvalidFunctionSelectionWarning(int max_function_count)
	{
		cerr << endl << "Please select integer from the list of offered functions, 1 to " << max_function_count << endl;

		cin.clear();
		cin.ignore();
		return;
	}

	int GetUserSelection(int max)
	{
		int user_selection = 0;
		cout << endl << "Please select the operation" << endl;	
		cin >> user_selection;

		if 
		( 
			!cin 
			|| user_selection < 1 
			|| user_selection > max 
		) 
		{
			PrintInvalidFunctionSelectionWarning( max );
			throw runtime_error("Invalid functionality selection");
		}
		
		return user_selection;
	}

	void DispatchSelectedOperation(int user_selection)
	{
			switch (user_selection)
			{
				case 1:
					DisplayRoster(roster);
					break;

				case 2:
					roster = AddStudent(roster, max_class_size);	
					break;

				case 3:
					roster = DeleteStudent(roster, grade);
					break;

				case 4:
					DisplayGrade(roster, grade);
					break;

				case 5:
					cout << "Exiting..." << endl; 
					exit(0);

				default:
					cout << "Invalid user selection" << endl;
					WaitForUser();
					break;
			}
	}

	int GetUserInputWithinIntegerRange(int min, int max)
	{
		int index_of_student_selected_for_deletion = 0;
		
		bool keep_polling_user = true;
		while ( keep_polling_user )
		{
			cin.clear();
			cin.ignore();
			cin >> index_of_student_selected_for_deletion;

			const auto [is_valid, validation_message] = ValidateUserInputWithinIntegerRange(min, max, index_of_student_selected_for_deletion);

			if (!is_valid) 
			{
				cout << endl << validation_message << endl;
			}
			
			keep_polling_user = !is_valid;
		}
		return index_of_student_selected_for_deletion;
	}
}


/* Side note: 
Below is an example of Doxygen comment, which can be thought as an enhancement of a regular comment. 
You probably noticed triple slash instead of usual double, also, various keywords starting with @.

Such comments can adorn various types and members and with use of respective tools 
can be converted in developer documentation (instead of writing documentation separately and from scratch). 

They also can also be picked up by tools like VS Code to provide integrated experience. 
For instance hover mouse over line in GetUserInputWithinIntegerRange() where this function is called from,
you will see a tooltip appearing, displaying functionality, expected input and output. 
Such "intellisense" tooltips are extremely valuable when you need to use
external libraries and need quick summary of what function there does and how to use it.

Obviously, as with regular comment, this has no impact on compiler of program execution,
it’s only meant to help readability and developer’s understanding. 

There are number of technologies that allow such enhanced commenting. 
You can read more about this particular one at https://www.doxygen.nl/index.html */


/// @brief function is validating user input, making sure a valid integer input was submitted by the user
/// @param min minimum acceptable valued
/// @param max maximum acceptable value
/// @param user_input actual value submitted by the user
/// @return boolean part is true if input was valid, and false if input was invalid. there is also an error message part, that's empty for valid scenario and contains error message for invalid scenario
tuple<bool, string> ctch1330::ValidateUserInputWithinIntegerRange(const int min, const int max, const int user_input)
{
	// function contains two bugs. they need to be identified and fixed for unit tests to pass. 	
	// next line would be a good place to put a break point
	if 
	( 
		!cin
		|| user_input < min // error1
		|| user_input > max 
	)
	{
		return {false, "Please enter integer within the range of current roster"};  // error2
	}
	else 
	{
		return {true, ""};
	}
}
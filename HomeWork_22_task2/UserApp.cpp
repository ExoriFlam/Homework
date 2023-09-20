#include <conio.h>
#include "UserApp.h"
#include "Defenitions.h"

void UserApp::run()
{
	
	file_manager.read_from_bin_to(acc_manager.get_users());
	do
	{
		console.init();

		console.draw_menu();

		console.input();


		if (console.get_chose())
		{
			if (console.get_state_menu() == START_MENU)
			{
				switch (console.get_param())
				{
				case REGISTER:
				{
					bool success_added = false;
					console.choice(ACTION);
					success_added = acc_manager.add_user(console.get_entered_user());

					if (success_added)
					{
						console.choice(SUCCESS);
					}
					else
					{
						console.choice(FAIL);
					}
				}

				break;

				case LOGIN:
				{
					

					bool success_login = false;
					console.choice();

					success_login = acc_manager.find_login(console.get_input_login(), console.get_input_password());

					if (success_login)
					{
						console.choice(SUCCESS);
						acc_manager.set_current_user(console.get_input_login());
						console.set_current_user_login(acc_manager.get_current_user_login_name());
						console.set_state_menu(USER_MENU);
					}
					else
					{
						console.choice(FAIL);
					}

				}
				break;
				case EXIT:
				{
					console.choice();
					file_manager.save_to_bin(acc_manager.get_users());
					file_manager.save_to_txt(acc_manager.get_users());
					exit(0);
					
				}
				break;



				default:
					break;
				}
			}
			else if (console.get_state_menu() == USER_MENU)
			{
				switch (console.get_param())
				{
				case USER_INFO:
				{
					console.choice();
					acc_manager.get_current_user().show();
					acc_manager.get_current_user().show_all_msg();
					_getch();
					system("cls");
				}
				break;

				case SEND_MESSAGE:
				{
					system("cls");
					acc_manager.show_all_emails();
					console.choice(ACTION);
					
					bool correct_email = acc_manager.find_email(console.get_buffer());
					if (correct_email)
					{
						
						console.choice(SUCCESS);
						acc_manager.add_user_msg(console.get_buffer(), console.get_buffer_msg());
						
					}
					else
					{
						console.choice(FAIL);
					}
				}
				break;
					

				case LOGOUT:
				{
					console.choice();
					acc_manager.set_defoult_user(User());
					console.set_param(0);
					console.set_state_menu(START_MENU);
					
				}
				break;

				default:
					break;
				}
			}
			

			console.set_chose(false);
		}

	} while (GetKeyState(VK_ESCAPE) >= 0);

	file_manager.save_to_bin(acc_manager.get_users());
	file_manager.save_to_txt(acc_manager.get_users());
	
}




#include "DictionaryApp.h"
#include <conio.h>
#include <csignal> 



void DictionaryApp::run()
{
	enum { ADD = 0, SHOW, SEARCH, WHRITE_TXT, WHRITE_BIN, SHOW_TXT, EXIT};
	
	file_manager.read_from_bin_to(tree_dictionary);

	do
	{
		console.init();
		console.draw_menu();
		console.input();


		if (console.get_chose())
		{
			switch (console.get_param())
			{
			case ADD:
			{
				console.choice(true);
				Translation entered_data{console.get_from_buff_eng(),console.get_from_buff_ru()};
				if (!(tree_dictionary.add(entered_data)))
				{
					console.choice(false);
				}
				
			}
				
				break;
			case SHOW:
			{
				console.choice();
				tree_dictionary.show();
				_getch();
				system("cls");
			}
				break;
			case SEARCH:
			{
				
				console.choice();
				console.set_buff_ru(tree_dictionary.get_translation(console.get_from_buff_eng()));
				console.choice(0);
			}
				break;
			case WHRITE_TXT:
			{
				console.choice(file_manager.save_to_txt(tree_dictionary));
				
			}
				break;
			case WHRITE_BIN:
			{
				console.choice(file_manager.save_to_bin(tree_dictionary));
				
			}
				break;
			case SHOW_TXT:
			{
				
				console.choice(true);
			}
			break;

			case EXIT:
			{
				file_manager.save_to_bin(tree_dictionary);
				console.choice(true);
			}
				break;

			

			default:
				break;
			}

			console.set_chose(false);
		}

	} while (GetKeyState(VK_ESCAPE) >= 0);
	
	file_manager.save_to_bin(tree_dictionary);

}

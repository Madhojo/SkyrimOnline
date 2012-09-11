//--------------------------------------------------------------------------------
/// @author Maxime GRIOT
//--------------------------------------------------------------------------------

#pragma once

namespace Skyrim
{
	namespace Overlay
	{
		//--------------------------------------------------------------------------------
		/// @brief A chat interface for the client
		//--------------------------------------------------------------------------------
		class ShardList
		{
		public:

			//--------------------------------------------------------------------------------
			/// @brief Hides the chat
			//--------------------------------------------------------------------------------
			void	Hide();

			//--------------------------------------------------------------------------------
			/// @brief Shows the chat
			//--------------------------------------------------------------------------------
			void	Show();

			//--------------------------------------------------------------------------------
			/// @brief Set the console's visibility
			/// @param n self explanatory
			//--------------------------------------------------------------------------------
			void	SetVisible(bool isVisible);

			//--------------------------------------------------------------------------------
			/// @brief Is the console visible or not
			/// @return visibility
			//--------------------------------------------------------------------------------
			bool	IsVisible();

			//--------------------------------------------------------------------------------
			/// @brief Updates the chat
			//--------------------------------------------------------------------------------
			void Update(double);

			bool Setup(){return true;}

			void Destroy(){}

			//--------------------------------------------------------------------------------
			/// @brief Handles an edit box accept event.
			/// @param _widget The widget firing the event.
			//--------------------------------------------------------------------------------
			void Handle_Click(MyGUI::WidgetPtr _widget);

			//--------------------------------------------------------------------------------
			/// @brief Handles an edit box accept event.
			/// @param _widget The widget firing the event.
			//--------------------------------------------------------------------------------
			void Handle_HostClick(MyGUI::WidgetPtr _widget);

			//--------------------------------------------------------------------------------
			/// @brief Constructor, do not call
			//--------------------------------------------------------------------------------
			ShardList(MyGUI::Gui*);

			//--------------------------------------------------------------------------------
			/// @brief Destructor, do not call
			//--------------------------------------------------------------------------------
			~ShardList();

			//--------------------------------------------------------------------------------
			/// @brief Add something to the console's log
			/// @param str The string to add
			//--------------------------------------------------------------------------------
			void	Log(const MyGUI::UString& str, const std::string& pIp);

			boost::signal<void(const std::string&)> OnShardPick;
			boost::signal<void()>					OnHost;

		private:

			//--------------------------------------------------------------------------------
			/// @brief Add something to the console's log
			/// @param str The string to add
			//--------------------------------------------------------------------------------
			void	_Log();
			//--------------------------------------------------------------------------------
			/// @brief The console's list box
			//--------------------------------------------------------------------------------
			MyGUI::ListPtr				mList;
			MyGUI::StaticTextPtr		mText;
			MyGUI::ButtonPtr			mButton;
			MyGUI::ButtonPtr			mHostButton;
			std::vector<std::string>	mIps;
			std::list<MyGUI::UString>	mMessages;
			boost::mutex				mMessagesMutex;
			//--------------------------------------------------------------------------------
			/// @brief The console's edit box
			//--------------------------------------------------------------------------------
			MyGUI::Gui*				mUI;
		};
	}
}
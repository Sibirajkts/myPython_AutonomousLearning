#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Song
{
    string name;
    string artist;
    int rating;
public:
    Song() = default;
    Song(string name,string artist,int rating):name{name},artist{artist},rating{rating}
    {}
    string get_name() const
    {
        return name;
    }
    string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }
    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
    friend ostream &operator<<(ostream &os,const Song &rhs);
};

ostream &operator<<(ostream &os, const Song &rhs)
{
    os<<setfill(' ')<<setw(20)<<left<<rhs.name
       <<setw(30)<<left<<rhs.artist
        <<setw(2)<<left<<rhs.rating;
    return os;
}

void display_menu()
{
    cout<<"\n F-- play first song"<<endl;
    cout<<"\n N-- play next song"<<endl;
    cout<<"\n P-- play previous song"<<endl;
    cout<<"\n A-- Add and play a new song at current location"<<endl;
    cout<<"\n L-- list the current playlist"<<endl;
    cout<<setfill('=')<<setw(30)<<" "<<endl;
    cout<<"Enter a selection (Q to quit): ";
}

void play_current_song(const Song &s)
{
    cout<<" Current Playing: "<<s.get_name()<<endl;
}

void display_playlist(const list<Song> &playlist, Song &current_song)
{
    cout<<" Current PlayList: "<<endl;
    for(auto &song:playlist)
    {
        cout<<song<<endl;
    }
    play_current_song(current_song);
}

int main()
{
    list<Song> playlist{
        {"song1","artist1",5},
        {"song2","artist2",4},
        {"song3","artist3",5},
        {"song4","artist4",3},
        {"song5","artist5",5},
    };
    list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    char c {};
    while (c != 'Q')
    {
        display_menu();
        cin>>c;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        switch((toupper(c)))
        {
            case 'F':
		{
                    current_song = playlist.begin();
                    play_current_song(*current_song);
		}
            break;
            case 'N':
		{
                    current_song++;
                    if(current_song == playlist.end())
                    {
                        current_song = playlist.begin();
                    }
                    play_current_song(*current_song);
		}
            break;
            case 'P':
		{
                    if(current_song == playlist.begin())
                    {
                        current_song = playlist.end();
                    }
                    current_song--;
                    play_current_song(*current_song);
		}
            break;
            case 'A':
		{
                    string  name = {},artist = {};
                    int rating;
                    cout<<"Adding a new song:"<<endl;
                    cout<<"Enter Song name:";
                    getline(cin, name);
                    cout<<"Enter Song Artist:";
                    getline(cin, artist);
                    cout<<"Enter your rating(1-5):";
                    cin>>rating;
                    playlist.insert(current_song, Song(name,artist,rating));
                    current_song--;
                    play_current_song(*current_song);         
		}
            break;
            case 'L':
		{
                    cout<<endl;
                    display_playlist(playlist, *current_song);
		}
            break;
            case 'Q':
		{
                    cout<<"xxxxx QUITING xxxxxxx"<<endl;
		}
            break;
            default:
		{
                    cout<<"Invalid Input.. Try again.."<<endl;
		}
            break;
        }
    }
    cout<<"BYEEE...!!!"<<endl;
    return 0;
}

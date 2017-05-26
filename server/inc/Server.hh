//
// Server.hh for server in /Users/leandr_g/Documents/Shared folder/IndieStudio/server/inc/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Fri May 26 03:18:28 2017 Gaëtan Léandre
// Last update Fri May 26 04:13:00 2017 Gaëtan Léandre
//

#ifndef             SERVER_HH_
#define             SERVER_HH_

#include            "Race.hh"
#include            "Message.hh"

class Server : public Group{
private:
    std::vector<Race> _races;

public:
    Server ();
    virtual ~Server ();
    Server(const Server &obj);
    Server    &operator=(const Server &obj);
    void startRace(Message const &message);
    void endRace(int id);
    bool deleteClientFromRaceById(int id);
    bool deleteClientFromRaceByFd(int fd);
    virtual bool deleteClientById(int id);
    virtual bool deleteClientByFd(int fd);
};

#endif /* !SERVER_HH_ */

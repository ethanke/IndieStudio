//
// GameManager.hh for gameManager in /Users/leandr_g/Documents/Shared folder/IndieStudio/server/inc/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Thu May 25 23:58:59 2017 Gaëtan Léandre
// Last update Fri May 26 04:15:48 2017 Gaëtan Léandre
//

#ifndef             GAMEMANAGER_HH_
#define             GAMEMANAGER_HH_

#include            "Message.hh"
#include            "Server.hh"

class GameManager {
private:
    std::unordered_map<int, Client> _clients;
    std::vector<Server> _servers;

public:
    GameManager();
    virtual ~GameManager ();
    GameManager(const GameManager &obj);
    GameManager    &operator=(const GameManager &obj);
    void addClient(int sock);
    void deleteClient(int sock);
    Client &getClientByFd(SOCKET fd);
    Client &getClientById(int id);
    int getClientsSize() const;
    void launchCommand(std::string json);
    void readClientByFdSet(fd_set *fdset);
    void readClientByFd(SOCKET fd);
    void writeClientByFd(SOCKET fd, std::string const &str);
    void readClientById(int id);
    void writeClientById(int id, std::string const &str);
    void stop();
    void setListener(fd_set *fdset, int &max);
};

#endif /* !GAMEMANAGER_HH_ */

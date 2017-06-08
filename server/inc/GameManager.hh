//
// GameManager.hh for gameManager in /Users/leandr_g/Documents/Shared folder/IndieStudio/server/inc/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Thu May 25 23:58:59 2017 Gaëtan Léandre
// Last update Wed Jun  7 13:51:00 2017 Gaëtan Léandre
//

#ifndef             GAMEMANAGER_HH_
#define             GAMEMANAGER_HH_

#include            "Message.hh"
#include            "Server.hh"

class GameManager {
private:
    std::unordered_map<int, Client> _clients;
    std::unordered_map<std::string, int> _operation;
    std::vector<Server> _servers;
    int _idMax = 1;

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
    void launchCommand(std::string const &json, SOCKET fd);
    void readClientByFdSet(fd_set *fdset);
    void readClientByFd(SOCKET fd);
    void writeClientByFd(SOCKET fd, std::string const &str);
    void readClientById(int id);
    void writeClientById(int id, std::string const &str);
    void stop();
    void setListener(fd_set *fdset, int &max);

    void getId(int fd);
    void setId(int fd, int id);
    void move(int fd);
    void addMoney(int fd, int id, int value);
    void getMoney(int fd, int id);
    void joinServer(int fd, int id, int value);
};

#endif /* !GAMEMANAGER_HH_ */

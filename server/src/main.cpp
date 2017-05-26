/*
** main.c for main in /Users/leandr_g/Documents/Shared folder/IndieStudio/server/src/
**
** Made by Gaëtan Léandre
** Login   <gaetan.leandre@epitech.eu>
**
** Started on  Wed May 24 12:31:16 2017 Gaëtan Léandre
** Last update	Thu May 25 02:32:52 2017 Gaëtan Léandre
*/

#include <iostream>
#include <Message.hh>
#include <ClientSocket.hh>

int             main()
{
    Message bonjour("test");
    Message subSession("anOther");
    Message test("test");

    subSession("Un autre") = "oui";
    bonjour.addContent("haha", "bebe") = "cece";
    bonjour("json") = "bravo";
    bonjour("json") = "pas de fail";
    bonjour["anOther"] = subSession;
    bonjour["anOther"]("Un autre") = "caca";
    bonjour["anOther"]("Un premier") = "prout";
    std::cout << bonjour.getJSON() << std::endl << std::endl;
    test.parseJSON(bonjour.getJSON());
    std::cout << test.getJSON() << std::endl;
    return (0);
}

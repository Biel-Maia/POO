#ifndef USUARIO_H
#define USUARIO_H


#include <map>
#include <string>
#include <vector>

/* Adm pode definir o que usuário tem ou não permissão de acesso.
Ex: Usuário pode acessar todos dados de Produção e Venda,
mas não pode alterar dados de Cliente.

Para isso, essa classe será instanciada dentro do login do
Usuário, e configurada a partir dele.
Ex: map<string classe, map<string metodo, bool permissao>> permissoes_de_acesso;
permissoes_de_acesso[VendaProduto][setProdutoVendido] = true;
permissoes_de_acesso[Cliente][setTelefone] = false;
*/

class Usuario
{
  private:
    std::string _tipo;
    std::string _user;
    std::string _senha;
    static Usuario* instancia_unica;
    std::vector<std::string> _classe;
    std::vector<std::string> _metodo;
    std::vector<bool> _permissao;


  public:
    Usuario
    (
      std::string tipo,
      std::string user,
      std::string senha
    );

    std::string getUser();
    std::string getSenha();
    void setSenha(std::string senha);
    static Usuario* getInstance();
    bool login(int, int);
    void setPermissao(std::string classe, std::string metodo, bool permissao);
    bool getPermissao(std::string classe, std::string metodo);
    ~Usuario();
};

#endif
#ifndef USUARIO_H
#define USUARIO_H

#include <map>
#include <string>

/* Adm pode definir o que usuário tem ou não permissão de acesso.
Ex: Usuário pode acessar todos dados de Produção e Venda,
mas não pode alterar dados de Cliente.

Para isso, essa classe será instanciada dentro do login do
Usuário, e configurada a partir dele.
Ex: map<string classe, map<string metodo, bool permissao>> permissoes_de_acesso;
permissoes_de_acesso[VendaProduto][setProdutoVendido] = true;
permissoes_de_acesso[Cliente][setTelefone] = false;
*/

class Usuario{

  private:
  std::string _tipo;
  std::string _user;
  std::string _senha;
  static Usuario* instancia_unica;
  map<string, map<string, bool>> permissoes_de_acesso;

  public:
  Usuario(
    std::string tipo,
    std::string user,
    std::string senha
  );

  std::string getUser();
  std::string getSenha();
  void setSenha(std::senha);
  static Usuario* getInstance();
  bool login(int, int);
  void setPermissao(string, string, bool);
  bool getPermissao(string, string);
};
#endif
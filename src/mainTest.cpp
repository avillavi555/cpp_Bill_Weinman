//#include


// Le decimos al compilador que esta funcion existe, pero que no esta aqui
// (ya la encontrara el enlazador)
extern int func_no_estatica();

// Le decimos al compilador que esta funcion existe, pero que no esta aqui
// Como esta funcion esta marcada como static, no la va a encontrar
extern int func_estatica();


int main()
{
  // Si se quita el comentario, el codigo no compila
  // func_estatica();

  func_no_estatica();
}

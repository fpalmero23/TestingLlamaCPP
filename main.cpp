// main.cpp
#include "llama.h"
#include <iostream>

int main() {
    std::cout << "hola mundo\n";
    // Inicializacion del modelo
    llama_model_params model_params = llama_model_default_params();
    const char * model_path = "C:\\workspace\\IA\\TestingLlamaCPP\\llama.cpp\\models\\Llama2_7B_Chat\\llama-2-7b-chat.Q5_K_M.gguf";
    llama_model * model = llama_load_model_from_file(model_path, model_params);
    if (!model) {
        std::cerr << "Error: no se pudo cargar el modelo desde " << model_path << std::endl;
        return 1;
    }
    std::cout << "Modelo cargado correctamente." << std::endl;
    // Configuracion contexto
    llama_context_params ctx_params = llama_context_default_params();
    ctx_params.n_ctx = 4096;  // tokens máximos en contexto
    llama_context* ctx = llama_new_context_with_model(model, ctx_params);
    if (!ctx) {
        std::cerr << "Error al crear el contexto\n";
        llama_free_model(model);
        return 1;
    }

    // Liberar memoria
    llama_free_model(model);
    return 0;
}
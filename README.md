# rocm-certif

Mon parcours d'apprentissage de la programmation GPU sur AMD avec **ROCm / HIP**, pour préparer la **ROCm Certification Associate** de l'AMD AI DevDay Paris (12 décembre 2026).

Je pars du C/C++ de base et j'avance jusqu'à l'optimisation et au profiling de kernels GPU. Chaque dossier numéroté correspond à une étape, avec son code et ses notes.

## Objectifs

- Revoir les bases du C et du C++ (pointeurs, mémoire, références, classes, STL)
- Comprendre le modèle d'exécution GPU (threads, blocs, grille, hiérarchie mémoire)
- Écrire, mesurer et optimiser des kernels HIP
- Profiler avec les outils ROCm (`rocprofv3`)
- Porter du code CUDA vers HIP (`hipify`)
- Faire le lien avec PyTorch sur ROCm

## Environnement

| Élément | Version |
|---|---|
| GPU | AMD Radeon RX 9070 (gfx1201, RDNA 4) |
| OS | Ubuntu 26.04 LTS |
| ROCm | 10.2.0 |
| Compilateur | `hipcc` (HIP 7.17) |
| PyTorch | 2.14.0+rocm10.2.0 |
| Éditeur | VSCodium + clangd |

## Structure

```
rocm-certif/
├── 00-intro-c-cpp/        # (Ré)introduction au C et au C++, sans GPU
├── 01-vecadd/      # Premier kernel HIP : addition de vecteurs
├── 02-matmul-naive/# Multiplication de matrices naïve
├── 03-matmul-shared/      # Tiling avec la mémoire partagée (__shared__)
├── 04-timing/      # Mesure de performance avec hipEvent
├── 05-profiling/   # Profiling avec rocprofv3
├── 06-hipify/      # Portage CUDA → HIP
├── compile_flags.txt      # Configuration clangd
└── README.md
```

Les binaires sont produits dans un sous-dossier `build/` de chaque étape et ne sont pas versionnés.

## Compilation

**C (dossier 00)** : warnings, infos de débogage et détection des erreurs mémoire

```bash
gcc -Wall -Wextra -g -fsanitize=address 00-intro-c-cpp/fichier.c -o 00-intro-c-cpp/build/fichier
```

**C++ (dossier 00)** :

```bash
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address 00-intro-c-cpp/fichier.cpp -o 00-intro-c-cpp/build/fichier
```

| Option | Rôle |
|---|---|
| `-Wall -Wextra` | Active la plupart des avertissements |
| `-g` | Informations de débogage (numéros de ligne dans les rapports) |
| `-fsanitize=address` | AddressSanitizer : détecte fuites, double free, accès hors limites |
| `-std=c++20` | Version du standard C++ |

**HIP (dossiers 01 et suivants)** :

```bash
hipcc --offload-arch=gfx1201 fichier.cpp -o build/fichier
```

> ⚠️ Compiler HIP **hors du venv PyTorch** (`deactivate`) ou appeler `usr/bin/hipcc` : le `hipcc` du venv ne trouve pas les bibliothèques ROCm du device.

## clangd et `compile_flags.txt`

`compile_flags.txt` n'est lu que par **clangd** (analyse dans l'éditeur), jamais par les compilateurs. clangd utilise le fichier le plus proche en remontant les dossiers :

- la racine contient la config HIP (`-x hip`, `--offload-arch=gfx1201`, `--rocm-path=...`, `-nogpulib`) utilisée par défaut,
- `00-intro-c-cpp/` a son propre fichier (`-Wall -Wextra`), pour que les `.c` soient analysés comme du C et les `.cpp` comme du C++. 

## Avancement

- [x] 00 — Intro C/C++
    - [x] Pointeurs, passage par adresse, tableaux
    - [x] malloc / free
    - [x] C++ : références, new/delete, std::vector
    - [x] Classes et RAII
- [ ] 01 — Addition de vecteurs
- [ ] 02 — Matmul naïve
- [ ] 03 — Matmul avec mémoire partagée
- [ ] 04 — Timing avec hipEvent
- [ ] 05 — Profiling rocprofv3
- [ ] 06 — hipify

### Contenu du dossier 00

| Fichier | Notion |
|---|---|
| `01_pointeurs.c` | Adresse (`&`), déréférencement (`*`) |
| `02_swap.c` | Passage par adresse |
| `03_tableaux.c` | Tableaux, arithmétique des pointeurs, `sizeof` |
| `04_malloc.c` | Allocation sur le tas, fuite détectée par ASan |
| `05_references.cpp` | Références C++ |
| `06_new_delete.cpp` | `new[]` / `delete[]` |
| `07_vector.cpp` | `std::vector`, boucles par valeur et par référence |
| `08_raii.cpp` | Classe RAII, copie interditen (double free) |

## Ressources

- [Documentation ROCm](https://rocm.docs.amd.com/)
- [HIP Programming Guide](https://rocm.docs.amd.com/projects/HIP/en/latest/)
- [rocprofv3](https://rocm.docs.amd.com/projects/rocprofiler-sdk/en/latest/)
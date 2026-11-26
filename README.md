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

## Compilation

Code C/C++ classique (dossier 00) :

```bash
g++ -std=c++17 -Wall -Wextra fichier.cpp -o programme
```

Code HIP :

```bash
hipcc --offload-arch=gfx1201 fichier.cpp -o programme
```

## Avancement

- [ ] 00 — Intro C/C++
    - [x] Pointeurs, passage par adresse, tableaux
    - [x] malloc / free
    - [x] C++ : références, new/delete, std::vector
    - [ ] Classes et RAII
- [ ] 01 — Addition de vecteurs
- [ ] 02 — Matmul naïve
- [ ] 03 — Matmul avec mémoire partagée
- [ ] 04 — Timing avec hipEvent
- [ ] 05 — Profiling rocprofv3
- [ ] 06 — hipify

## Ressources

- [Documentation ROCm](https://rocm.docs.amd.com/)
- [HIP Programming Guide](https://rocm.docs.amd.com/projects/HIP/en/latest/)
- [rocprofv3](https://rocm.docs.amd.com/projects/rocprofiler-sdk/en/latest/)
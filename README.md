
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/ef137d4d3b324b9fb907ba5a8e0a788c)](https://www.codacy.com/manual/eelaazmi/ft_printf_42_cursus?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Alcheemiist/ft_printf_42_cursus&amp;utm_campaign=Badge_Grade)

# ft_priuntf_42_cursus

Recodez votre printf !

# Usage identique à la fonction printf :

  • ft_printf("Mon texte a afficher %Mon_type Mon autre texte a afficher", argument de type Mon_type);
  Principales Notions

  • Creation d'un parser irréprochable,
  • Initiation aux fonctions variadiques,
  • Apprehension de tous les typages possibles en C.
  Résumé du sujet :

  Quelque soit le langage de programmation considéré, la fonction printf (ou ses équivalents) est toujours une fonction extrêment pratique. La raison principale est bien évidemment le confort de formatage, et le support de types hétérogènes en nombre variable. Certaines variantes proposent même de pouvoir écrire la chaine de caractères résultat sur un file descriptor ou un stream particulier, ou bien même carrément de récuperer cette chaine sans l’imprimer. Bref, c’est une fonction incontournable que nous vous proposons de recoder aujourd’hui.

  La versatilité de la fonction printf en C représente pour nous un excellent exercice de programmation. D’une difficulté modérée, ce projet va vous permettre de découvrir les fonctions variadiques en C dans un contexte particulièrement adapté, et de voir un excellent exemple d’un “dispatcher” rudimentaire implémenté en C à l’aide d’un tableau de pointeurs sur fonctions.

# Objectifs

  • Vous devez recoder la fonction printf de la librairie C.
  • Votre fonction s’appelera ft_printf et sera prototypée de la même façon que printf.
  • Vous ne ferez pas la gestion de buffer présente dans la fonction printf de la librairie C.
  • Vous devez gérer les conversions suivantes : sSpdDioOuUxXcC
  • Vous devez gérer le %%
  • Vous devez gérer les flags #0-+ et espace
  • Vous devez gérer la taille minimum du champ
  • Vous devez gérer la précision
  • Vous devez gérer les flags hh h l ll j z

# Fonctions autorisées

  ◦ write ◦ malloc ◦ free ◦ exit ◦ les fonctions du man 3 stdarg

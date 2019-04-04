Afin d'obtenir le Main.exe qui vous aide à compiler votre programme,
Exécutez-vous la commande suivante:
make
(S'il existe des erreurs de persmission sur l'exécutable antlr,
Faites chmod +x ./antlr pour ajouter le droit d'exécution)

Pour compiler votre programme souhaité,
Copiez-le dans le fichier test.c,
Puis lancez la ligne de commande ci-dessous:
./Main.exe test.c
Ensuite, un fichier test.s sera généré.
Puis, exécuter la ligne de commande suivante pour obtenir l'exécutable final:
make build
Et puis, lancez l'exécutable pour visualiser le résultat:
./a.out
echo $? (Instruction pour afficher la valeur de retour)
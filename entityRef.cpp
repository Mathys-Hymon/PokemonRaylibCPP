﻿#include "entityRef.h"



std::vector<Ability> abilitys = {
	{"",0,normal,0},
{"charge", 40, normal, 20},
{"ultralaser", 150, normal, 5},
{"revers", 70, normal, 50},
{"vive-attaque", 50, normal, 30},
{"coud'krâne", 85, normal, 55},
{"flammèche", 40, fire, 25},
{"déflagration", 110, fire, 70},
{"poing de feu", 75, fire, 40},
{"roue de feu", 60, fire, 35},
{"boutefeu", 120, fire, 80},
{"pistolet à o", 40, water, 25},
{"surf", 90, water, 60},
{"canon à o", 150, water, 100},
{"aqua-queue", 80, water, 50},
{"bulles d'o", 65, water, 40},
{"fouet lianes", 45, grass, 30},
{"lance-soleil", 120, grass, 4},
{"tranch'herbe", 55, grass, 35},
{"bomb-graine", 80, grass, 50},
{"méga-sangsue", 75, grass, 45},
{"éclair", 40, electric, 25},
{"tonnerre", 90, electric, 60},
{"élecanon", 120, electric, 80},
{"étincelle", 65, electric, 40},
{"poing-éclair", 75, electric, 50},
{"éclats glace", 40, ice, 25},
{"blizzard", 110, ice, 70},
{"rayon glace", 95, ice, 60},
{"avalanche", 80, ice, 50},
{"carapace glace", 50, ice, 30},
{"poing-karaté", 50, fighting, 35},
{"dynamopoing", 100, fighting, 65},
{"balayage", 55, fighting, 40},
{"casse-brique", 75, fighting, 50},
{"mach punch", 40, fighting, 30},
{"dard-venin", 35, poison, 20},
{"bomb-beurk", 80, poison, 55},
{"toxik", 90, poison, 60},
{"piège de venin", 70, poison, 45},
{"détricanon", 120, poison, 80},
{"séisme", 100, ground, 70},
{"tunnel", 80, ground, 50},
{"coud'boue", 55, ground, 35},
{"piétisol", 65, ground, 40},
{"tourbi-sable", 35, ground, 25},
{"picpic", 35, flying, 20},
{"aéropique", 60, flying, 40},
{"vol", 90, flying, 55},
{"piqué", 120, flying, 80},
{"tranch'air", 75, flying, 50},
{"choc mental", 50, psychic, 30},
{"psyko", 90, psychic, 60},
{"prescience", 120, psychic, 80},
{"dard-nuée", 40, bug, 25},
{"bourdon", 90, bug, 60},
{"bourdon fatal", 120, bug, 80},
{"piqûre", 65, bug, 40},
{"lame d'air", 75, bug, 50},
{"jet-pierres", 50, rock, 30},
{"lame de roc", 100, rock, 65},
{"éboulement", 110, rock, 70},
{"exploforce", 120, rock, 80},
{"tomberoche", 80, rock, 50},
{"ball'ombre", 80, ghost, 55},
{"ombre nocturne", 55, ghost, 40},
{"maléfice", 90, ghost, 60},
{"saisie spectrale", 120, ghost, 80},
{"vent mauvais", 65, ghost, 45},
 {"colère", 120, dragon, 80},
{"dracogriffe", 80, dragon, 50},
{"éclat magique", 75, dragon, 45},
{"dracochoc", 90, dragon, 60},
{"lance-flamme", 110, dragon, 70},
{"tranche-nuit", 70, dark, 45},
{"crocs éclair", 65, dark, 40},
{"morsure", 60, dark, 35},
{"ball'ombre", 80, dark, 55},
{"poursuite", 40, dark, 30},
{"tête de fer", 80, steel, 55},
{"lame de roc", 100, steel, 70},
{"coup d'boule", 70, steel, 45},
{"griffe acier", 50, steel, 30},
{"plaie-croix", 80, steel, 50},
{"éclat magique", 75, fairy, 45 },
{"métronome", 0, fairy, 20},
{"dernier recours", 140, fairy, 90},
{"choc féerique", 65, fairy, 40},
{"vibra soin", 0, fairy, 30},
};
std::vector<Pokemon> allPokemons = {
{"bulbizarre", "il porte une graine sur le dos depuis sa naissance. en grandissant, la graine devient de plus en plus grosse.", grass, 2, 49, abilitys[16], abilitys[17]},
{"herbizarre", "herbizarre émet un parfum très doux lorsqu'il est sur le point de fleurir. la fleur se développe lorsqu'il atteint la maturité.", grass, 3, 62, abilitys[16], abilitys[17]},
{"florizarre", "la plante sur le dos de florizarre prend une couleur vive et émet une odeur très agréable quand il est en pleine santé.", grass, 4, 82, abilitys[16], abilitys[17]},
{"salameche", "la flamme qui brûle au bout de sa queue indique son état émotionnel. elle brûle plus fort quand il est excité.", fire, 2, 52, abilitys[5], abilitys[9]},
{"reptincel", "reptincel a une flamme beaucoup plus forte que salameche. elle brûle si intensément qu'il peut chauffer ses environs.", fire, 2, 60, abilitys[5], abilitys[36]},
{"dracaufeu", "dracaufeu a des ailes qui brillent dans le noir. il est fier de ces ailes magnifiques et les utilise pour voler majestueusement dans le ciel.", fire, 3, 78, abilitys[5], abilitys[32]},
{"carapuce", "le dos de carapuce est un peu dur. quand il est menacé, il se retire à l'intérieur de sa carapace pour se protéger.", water, 1, 50, abilitys[10], abilitys[12]},
{"carabaffe", "carabaffe a une coquille très solide qui devient plus résistante à mesure qu'il évolue. elle lui offre une excellente protection.", water, 2, 65, abilitys[10], abilitys[11]},
{"tortank", "tortank peut pulvériser de l'eau à haute pression avec une force telle qu'il peut facilement renverser de grands bâtiments.", water, 3, 80, abilitys[10], abilitys[37]},
{"Chenipan", "Chenipan est très petit et fragile. Il peut libérer des poils urticants pour se défendre contre les prédateurs.", bug, 1, 45, abilitys[51], abilitys[36]},
{"Chrysacier", "Chrysacier a une coque dure qui le protège des attaques. Il devient immobile pendant cette étape d'évolution.", bug, 2, 50, abilitys[51], abilitys[4]},
{"Papilusion", "Papilusion est le stade final de l'évolution de Chenipan. Il a des ailes colorées et peut disperser des poudres pour divers effets.", bug, 3, 60, abilitys[51], abilitys[35]},
{"Aspicot", "Aspicot aime se cacher dans les forêts et les buissons. Il peut utiliser ses crochets venimeux pour se défendre contre les prédateurs.", bug, 1, 40, abilitys[51], abilitys[31]},
{"Coconfort", "Coconfort se transforme en chrysalide pendant cette étape d'évolution. Il est vulnérable aux attaques pendant cette période.", bug, 2, 45, abilitys[51], abilitys[4]},
{"Dardargnan", "Dardargnan est le stade final de l'évolution d'Aspicot. Il a des aiguillons venimeux sur tout le corps.", bug, 3, 65, abilitys[51], abilitys[30]},
{"Roucool", "Roucool est un Pokémon oiseau très commun. Il peut voler à des vitesses élevées et est souvent utilisé par les dresseurs pour les voyages rapides.", flying, 1, 40, abilitys[54], abilitys[32]},
{"Roucoups", "Roucoups évolue à partir de Roucool. Il a des serres tranchantes et peut infliger des dégâts considérables avec ses attaques aériennes.", flying, 2, 55, abilitys[54], abilitys[32]},
{"Roucarnage", "Roucarnage est le stade final de l'évolution de Roucool. Il peut voler à des altitudes extrêmement élevées et repérer ses proies de loin.", flying, 3, 80, abilitys[54], abilitys[32]},
{"Rattata", "Rattata est un Pokémon très agile qui se reproduit rapidement. Il peut ronger presque n'importe quoi avec ses dents.", normal, 1, 30, abilitys[50], abilitys[33]},
{"Rattatac", "Rattatac évolue à partir de Rattata. Il a des dents très tranchantes et peut mordre à travers des objets solides.", normal, 2, 55, abilitys[50], abilitys[33]},
{"Piafabec", "Piafabec a un bec long et pointu qu'il utilise pour attraper des insectes. Il est également capable d'apprendre des attaques de type vol.", normal, 1, 40, abilitys[54], abilitys[32]},
{"Rapasdepic", "Rapasdepic évolue à partir de Piafabec. Son bec devient plus grand et plus fort, lui permettant de perforer même les objets les plus durs.", normal, 2, 65, abilitys[54], abilitys[32]},
{"Abo", "Abo a des crochets venimeux et peut libérer des toxines pour se défendre. Il est souvent trouvé dans des endroits sombres et humides.", poison, 1, 35, abilitys[49], abilitys[30]},
{"Arbok", "Arbok est le stade final de l'évolution d'Abo. Il a une capuche menaçante qu'il déploie lorsqu'il se sent menacé.", poison, 2, 60, abilitys[49], abilitys[30]},
{"pikachu", "il possède une petite poche dans ses joues où il stocke de l'électricité. il la libère en cas de danger.", electric, 2, 60, abilitys[21], abilitys[3]},
{"raichu", "la queue de raichu génère une charge électrique puissante. il peut parfois donner des chocs à des objets en touchant simplement la queue.", electric, 3, 75, abilitys[21], abilitys[2]},
{"sabelette", "sabelette creuse un terrier pour vivre. si le terrier est menacé, il s'enfuit à une vitesse incroyable.", ground, 1, 50, abilitys[40], abilitys[41]},
{"sablaireau", "sablaireau est capable de creuser des tunnels de plusieurs kilomètres en une seule nuit. il est très territorial.", ground, 2, 60, abilitys[40], abilitys[19]},
{"nidoran♀", "nidoran♀ a un sens aigu de l'odorat. il peut détecter des odeurs faibles et repérer ses proies à distance.", poison, 1, 55, abilitys[29], abilitys[42]},
{"nidorina", "l'odorat de nidorina est encore plus développé que celui de nidoran♀. elle utilise son sens de l'odorat pour communiquer avec d'autres pokémon.", poison, 2, 70, abilitys[29], abilitys[43]},
{"nidoqueen", "nidoqueen est très protecteur envers ses petits. il peut devenir agressif s'il pense que sa progéniture est en danger.", poison, 3, 90, abilitys[29], abilitys[7]},
{"nidoran♂", "nidoran♂ a une corne venimeuse sur sa tête. il utilise cette corne pour se défendre contre les prédateurs.", poison, 1, 46, abilitys[37], abilitys[42]},
{"nidorino", "la corne de nidorino devient plus grande et plus aiguisée à mesure qu'il évolue. il utilise sa corne pour combattre d'autres mâles.", poison, 2, 61, abilitys[37], abilitys[43]},
{"nidoking", "nidoking possède une force physique incroyable. il peut détruire un bâtiment en utilisant seulement sa puissance musculaire.", poison, 3, 81, abilitys[37], abilitys[7]},
{"mélofée", "les œufs de mélofée ont une grande valeur car ils sont considérés comme des joyaux. il est très rare d'en trouver un.", normal, 1, 70, abilitys[53], abilitys[54]},
{"mélodelfe", "mélodelfe peut guérir les blessures avec son chant. il a un timbre de voix magique qui apaise même les cœurs les plus agités.", normal, 2, 95, abilitys[53], abilitys[55]},
{"goupix", "goupix a une fourrure qui brûle d'un rouge vif. en hiver, sa fourrure devient plus épaisse pour le protéger du froid.", fire, 1, 38, abilitys[6], abilitys[9]},
{"feunard", "feunard est connu pour sa ruse et son intelligence. il est capable de manipuler le feu et de l'utiliser à des fins offensives.", fire, 2, 73, abilitys[6], abilitys[22]},
{"rondoudou", "les ondes qu'il émet sont si apaisantes qu'elles endorment les personnes et les pokémon qui les entendent.", normal, 1, 55, abilitys[49], abilitys[57]},
{"grodoudou", "grodoudou peut contrôler les émotions des gens en faisant vibrer ses ondes vocales. il utilise cette capacité pour apaiser les conflits.", normal, 2, 140, abilitys[49], abilitys[57]},
{"nosferapti", "nosferapti se nourrit du sang des autres pokémon. il se cache dans l'obscurité et utilise ses ailes silencieuses pour approcher sa proie.", poison, 1, 40, abilitys[60], abilitys[61]},
{"nosferalto", "nosferalto évolue grâce à l'influence de la lune. il devient plus actif la nuit et recherche activement des proies.", poison, 2, 75, abilitys[60], abilitys[62]},
{"mystherbe", "mystherbe émet une odeur enivrante qui endort ceux qui la respirent. il utilise cette capacité pour échapper à ses ennemis.", grass, 1, 45, abilitys[15], abilitys[27]},
{"ortide", "ortide est capable de détecter les émotions des autres pokémon grâce à son antenne. il peut communiquer sans utiliser de cris.", grass, 2, 60, abilitys[15], abilitys[14]},
{"rafflesia", "rafflesia libère une odeur nauséabonde pour repousser les ennemis. cette odeur est si forte qu'elle peut rendre les pokémon adverses malades.", grass, 3, 75, abilitys[15], abilitys[27]},
{"paras", "paras possède des champignons sur son dos qui poussent en symbiose avec lui. les champignons deviennent plus gros lorsqu'il évolue.", bug, 1, 35, abilitys[62], abilitys[31]},
{"parasect", "parasect est contrôlé par le champignon sur son dos. il agit instinctivement et suit les ordres du champignon.", bug, 2, 60, abilitys[62], abilitys[30]},
{"mimitoss", "mimitoss libère des spores toxiques dans l'air pour repousser les ennemis. il peut également hypnotiser les proies avec ses yeux.", bug, 1, 60, abilitys[51], abilitys[30]},
{"aéromite", "aéromite a des ailes très petites qui ne lui permettent pas de voler. il saute de branche en branche pour se déplacer.", bug, 2, 90, abilitys[51], abilitys[32]},
{"taupiqueur", "taupiqueur aime creuser des tunnels. il peut creuser jusqu'à 60 km en une journée pour chercher de la nourriture.", ground, 1, 10, abilitys[39], abilitys[29]},
{"triopikeur", "triopikeur possède trois griffes acérées qu'il utilise pour creuser des tunnels complexes sous terre.", ground, 2, 35, abilitys[39], abilitys[36]},
{"miaouss", "il adore collectionner des objets brillants. si quelque chose brille, il ne peut s'empêcher de le voler.", normal, 1, 40, abilitys[50], abilitys[58]},
{"persian", "persian a une fourrure douce et soyeuse qui est très prisée. il peut se faufiler silencieusement pour surprendre ses proies.", normal, 2, 65, abilitys[50], abilitys[58]},
{"psykokwak", "les pouvoirs psychiques de psykokwak s'améliorent à mesure qu'il grandit. il utilise des ondes cérébrales pour nager.", water, 1, 50, abilitys[23], abilitys[14]},
{"akwakwak", "akwakwak est capable de créer des tourbillons dans l'eau en agitant sa queue. il utilise cette technique pour capturer ses proies.", water, 2, 80, abilitys[23], abilitys[1]},
{"ferosinge", "il peut lancer plus de 500 coups de poing par minute. toutefois, il devient confus s'il manque sa cible.", fighting, 1, 55, abilitys[33], abilitys[41]},
{"colossinge", "colossinge devient très agressif lorsqu'il est en colère. il est extrêmement puissant et peut renverser de grands obstacles.", fighting, 2, 80, abilitys[33], abilitys[4]},
{"caninos", "caninos est très fidèle à son dresseur. il protège son maître avec loyauté et est prêt à affronter n'importe quel danger.", fire, 1, 55, abilitys[3], abilitys[10]},
{"arcanin", "arcanin est réputé pour sa vitesse et sa puissance. il est capable de parcourir de longues distances à une vitesse incroyable.", fire, 2, 90, abilitys[3], abilitys[37]},
{"ptitard", "ptitard peut vivre dans n'importe quel type d'eau, même celle qui est très sale. il mute pour s'adapter à son environnement.", water, 1, 40, abilitys[38], abilitys[11]},
{"têtarte", "têtarte possède de puissantes pattes qui lui permettent de nager rapidement. il peut sauter de l'eau pour attraper des proies.", water, 2, 65, abilitys[38], abilitys[24]},
{"tartard", "tartard est capable de nager à une vitesse incroyable. il peut parcourir de longues distances en un temps record.", water, 3, 90, abilitys[38], abilitys[37]},
{"abra", "abra dort pendant la majorité de la journée. il est capable de se téléporter instantanément pour échapper aux prédateurs.", psychic, 1, 25, abilitys[43], abilitys[22]},
{"kadabra", "kadabra possède un pouvoir télépathique très fort. il peut lire les pensées des autres et même prédire l'avenir.", psychic, 2, 40, abilitys[43], abilitys[30]},
{"alakazam", "alakazam a un qi extrêmement élevé. ses pouvoirs psychiques sont si forts qu'il peut plier une cuillère avec son esprit.", psychic, 3, 55, abilitys[43], abilitys[50]},
{"machoc", "machoc est un pokémon très fort qui aime s'entraîner. il devient encore plus puissant à mesure qu'il évolue.", fighting, 1, 70, abilitys[5], abilitys[49]},
{"machopeur", "machopeur a des muscles très développés qui lui confèrent une force incroyable. il peut soulever des objets très lourds.", fighting, 2, 80, abilitys[5], abilitys[32]},
{"mackogneur", "mackogneur est un expert en arts martiaux. il peut lancer des coups de poing si rapidement qu'ils sont invisibles à l'œil nu.", fighting, 3, 90, abilitys[5], abilitys[4]},
{"chetiflor", "chetiflor se nourrit de la sève des arbres. il peut étirer ses bras pour atteindre les branches les plus éloignées.", grass, 1, 45, abilitys[28], abilitys[27]},
{"boustiflor", "boustiflor a un odorat très développé. il peut détecter l'odeur des proies à plusieurs kilomètres de distance.", grass, 2, 60, abilitys[28], abilitys[11]},
{"empiflor", "empiflor est carnivore et se nourrit de petits pokémon. il attire ses proies avec son odeur sucrée avant de les dévorer.", grass, 3, 75, abilitys[28], abilitys[7]},
{"tentacool", "tentacool flotte à la surface de l'eau en utilisant ses tentacules pour capturer des proies. il peut sécréter du poison.", water, 1, 40, abilitys[13], abilitys[14]},
{"tentacruel", "tentacruel est capable de nager à des profondeurs extrêmes. ses tentacules sont très puissants et peuvent saisir des proies facilement.", water, 2, 80, abilitys[13], abilitys[23]},
{"racaillou", "racaillou aime se cacher dans les grottes. il est très territorial et peut devenir agressif s'il sent une menace.", rock, 1, 40, abilitys[47], abilitys[58]},
{"gravalanch", "gravalanch est très robuste et peut résister à de puissantes attaques. il peut rouler à grande vitesse pour écraser ses ennemis.", rock, 2, 55, abilitys[47], abilitys[57]},
{"grolem", "grolem est le stade final de l'évolution de racaillou. il est extrêmement puissant et peut soulever des rochers énormes.", rock, 3, 80, abilitys[47], abilitys[58]},
{"ponyta", "ponyta a une crinière de feu qui brille d'une lumière éblouissante. il court à des vitesses incroyables.", fire, 1, 50, abilitys[3], abilitys[9]},
{"galopa", "galopa est capable de courir sur l'eau avec ses sabots enflammés. il est connu pour sa grâce et sa vitesse.", fire, 2, 65, abilitys[3], abilitys[32]},
{"ramoloss", "ramoloss est lent et paresseux. il passe la plupart de son temps à dormir au fond de l'eau pour éviter les prédateurs.", water, 1, 90, abilitys[10], abilitys[24]},
{"flagadoss", "flagadoss est capable de flotter sur l'eau sans se fatiguer grâce à sa structure corporelle unique. il est très paisible.", water, 2, 95, abilitys[10], abilitys[2]},
{"magnéti", "magnéti génère un puissant champ magnétique. il est capable d'attirer et de coller à lui des objets métalliques.", electric, 1, 25, abilitys[22], abilitys[3]},
{"magnéton", "magnéton est constitué de trois magnéti fusionnés. il génère un champ magnétique encore plus puissant.", electric, 2, 50, abilitys[22], abilitys[36]},
{"canarticho", "canarticho a une longue tige fine sur sa tête qui ressemble à une plante. il utilise cette tige pour pêcher sa nourriture.", normal, 1, 60, abilitys[45], abilitys[46]},
{"doduo", "doduo a deux têtes qui fonctionnent indépendamment l'une de l'autre. il peut courir très rapidement pour échapper aux prédateurs.", normal, 2, 70, abilitys[45], abilitys[55]},
{"dodrio", "dodrio a trois têtes qui sont capables de communiquer entre elles. il peut attaquer plusieurs ennemis simultanément.", normal, 3, 80, abilitys[45], abilitys[55]},
{"otaria", "otaria possède une couche de graisse épaisse qui lui permet de flotter dans l'eau. il se nourrit principalement de poissons.", water, 1, 65, abilitys[12], abilitys[23]},
{"lamantine", "lamantine peut nager à des vitesses incroyables en utilisant ses nageoires. il est très agile dans l'eau.", water, 2, 90, abilitys[12], abilitys[8]},
{"tadmorv", "tadmorv est constitué de déchets toxiques. il sécrète une substance corrosive qui peut dissoudre presque tout.", poison, 1, 80, abilitys[63], abilitys[31]},
{"grotadmorv", "grotadmorv est encore plus toxique que tadmorv. il peut émettre des gaz nocifs qui empoisonnent l'air autour de lui.", poison, 2, 105, abilitys[63], abilitys[30]},
{"kokiyas", "kokiyas a une coquille très dure qui le protège des prédateurs. il peut également se cacher dans sa coquille pour se défendre.", water, 1, 30, abilitys[20], abilitys[36]},
{"crustabri", "crustabri a une coquille très solide qui est presque impossible à briser. il peut également l'utiliser pour écraser ses ennemis.", water, 2, 50, abilitys[20], abilitys[37]},
{"fantominus", "fantominus est constitué de gaz vénéneux. il peut se faufiler à travers les fissures et les fissures pour échapper à ses ennemis.", ghost, 1, 30, abilitys[64], abilitys[65]},
{"spectrum", "spectrum est attiré par les émotions négatives des gens. il peut se rendre invisible pour échapper à la détection.", ghost, 2, 45, abilitys[64], abilitys[66]},
{"ectoplasma", "ectoplasma se nourrit des rêves des gens endormis. il peut créer des illusions pour effrayer ses ennemis.", ghost, 3, 60, abilitys[64], abilitys[65]},
{"onix", "onix est un serpent de roche géant. il peut creuser des tunnels dans le sol pour se déplacer rapidement.", rock, 2, 35, abilitys[61], abilitys[58]},
{"soporifik", "soporifik libère un gaz hypnotique qui endort ses ennemis. il peut également lire les pensées des autres.", psychic, 1, 60, abilitys[47], abilitys[22]},
{"hypnomade", "hypnomade peut hypnotiser les gens en les regardant dans les yeux. il utilise cette capacité pour échapper aux prédateurs.", psychic, 2, 85, abilitys[47], abilitys[43]},
{"krabby", "krabby a une pince très puissante qu'il utilise pour attraper des proies. il est également capable de casser des objets durs.", water, 1, 30, abilitys[1], abilitys[37]},
{"krabboss", "krabboss a une pince encore plus puissante que krabby. il peut écraser des coquilles dures sans aucun problème.", water, 2, 50, abilitys[1], abilitys[37]},
{"voltorbe", "voltorbe stocke de l'électricité dans son corps. il peut exploser à tout moment s'il se sent menacé.", electric, 1, 40, abilitys[3], abilitys[23]},
{"électrode", "électrode est très instable et peut exploser à la moindre perturbation. il peut libérer une grande quantité d'énergie en une seule explosion.", electric, 2, 60, abilitys[3], abilitys[37]},
{"noeunoeuf", "noeunoeuf est composé de plusieurs œufs. il s'accroche fermement à sa proie avec ses bras pour l'empêcher de s'échapper.", grass, 1, 60, abilitys[15], abilitys[27]},
{"noadkoko", "noadkoko évolue à partir de noeunoeuf. il a un corps plus grand et plus robuste.", grass, 2, 95, abilitys[15], abilitys[8]},
{"osselait", "osselait porte un crâne d'adulte sur sa tête. il est très protecteur envers son crâne et le considère comme un trésor.", ground, 1, 50, abilitys[39], abilitys[36]},
{"ossatueur", "ossatueur utilise l'os qu'il porte comme arme. il peut frapper ses ennemis avec une force incroyable.", ground, 2, 60, abilitys[39], abilitys[33]},
{"kicklee", "kicklee est un expert en arts martiaux. il peut donner plusieurs coups de pied en une seconde.", fighting, 1, 50, abilitys[33], abilitys[35]},
{"tygnon", "tygnon utilise des mouvements de karaté pour attaquer ses ennemis. il peut casser des planches de bois avec ses poings puissants.", fighting, 2, 50, abilitys[33], abilitys[4]},
{"excelangue", "excelangue a une langue très longue qu'il utilise pour attraper sa proie. il peut lécher sa proie pour la paralyser.", normal, 1, 90, abilitys[36], abilitys[57]},
{"smogo", "smogo libère des gaz toxiques qui polluent l'air autour de lui. il est souvent évité en raison de son odeur nauséabonde.", poison, 1, 40, abilitys[63], abilitys[31]},
{"smogogo", "smogogo est encore plus toxique que smogo. il peut émettre des gaz corrosifs qui endommagent l'environnement.", poison, 2, 65, abilitys[63], abilitys[30]},
{"rhinocorne", "rhinocorne a une peau très dure qui le protège des attaques ennemies. il peut charger ses ennemis avec ses puissantes cornes.", ground, 1, 80, abilitys[33], abilitys[58]},
{"rhinoféros", "rhinoféros est plus grand et plus robuste que rhinocorne. il peut défoncer des murs avec ses cornes puissantes.", ground, 2, 105, abilitys[33], abilitys[58]},
{"leveinard", "leveinard a un cœur énorme qui lui permet de guérir les blessures des autres pokémon. il est très apprécié des dresseurs.", normal, 1, 250, abilitys[11], abilitys[2]},
{"saquedeneu", "saquedeneu a des lianes très tranchantes qu'il utilise pour capturer des proies. il peut aussi les utiliser pour se balancer d'arbre en arbre.", grass, 1, 60, abilitys[27], abilitys[35]},
{"kangourex", "kangourex porte toujours son petit dans sa poche. il est très protecteur envers son petit et peut devenir agressif s'il est menacé.", normal, 1, 105, abilitys[52], abilitys[50]},
{"hypotrempe", "hypotrempe a une queue en spirale qu'il utilise comme une hélice pour nager rapidement. il est très agile dans l'eau.", water, 1, 30, abilitys[23], abilitys[37]},
{"hypocéan", "hypocéan évolue à partir d'hypotrempe. sa queue en spirale lui permet de nager à des vitesses incroyables.", water, 2, 55, abilitys[23], abilitys[1]},
{"poissirène", "poissirène chante une mélodie captivante pour attirer les marins. il peut également utiliser son chant pour endormir ses ennemis.", water, 1, 45, abilitys[23], abilitys[57]},
{"poissoroy", "poissoroy a une couronne majestueuse sur la tête. il est très territorial et protège son territoire avec ferveur.", water, 2, 80, abilitys[23], abilitys[37]},
{"stari", "stari a un corps en forme d'étoile. il peut régénérer ses membres s'ils sont coupés.", water, 1, 30, abilitys[12], abilitys[36]},
{"staross", "staross évolue à partir de stari. il a un corps en forme d'étoile et peut utiliser des pouvoirs psychiques pour attaquer ses ennemis.", water, 2, 60, abilitys[12], abilitys[36]},
{"m. mime", "m. mime crée des barrières invisibles en pliant l'air. il utilise ces barrières pour se protéger et pour piéger ses ennemis.", psychic, 1, 40, abilitys[43], abilitys[14]},
{"insecateur", "insecateur a des lames très tranchantes sur ses pinces. il peut couper des branches d'arbres épaisses en une seule attaque.", bug, 1, 70, abilitys[51], abilitys[4]},
{"lippoutou", "lippoutou utilise des mouvements gracieux pour dérouter ses ennemis. il peut également donner des baisers glacés pour geler ses adversaires.", ice, 1, 65, abilitys[12], abilitys[43]},
{"élektek", "élektek génère de l'électricité en se déplaçant. il peut stocker de l'électricité dans son corps pour l'utiliser dans ses attaques.", electric, 1, 65, abilitys[22], abilitys[37]},
{"magmar", "magmar a un corps enflammé qui brûle à une température extrêmement élevée. il utilise le feu dans ses attaques.", fire, 1, 65, abilitys[6], abilitys[37]},
{"scarabrute", "scarabrute est extrêmement fort et peut soulever des objets très lourds. il est souvent utilisé pour des travaux de construction.", bug, 1, 70, abilitys[64], abilitys[4]},
{"tauros", "tauros est très territorial et charge quiconque s'approche de son territoire. il est rapide et puissant.", normal, 1, 75, abilitys[50], abilitys[33]},
{"magicarpe", "magicarpe est un pokémon faible qui ne peut pas attaquer. il se développe en un pokémon puissant lorsqu'il évolue en gyarados.", water, 1, 20, abilitys[38], abilitys[23]},
{"léviator", "léviator est redouté pour sa puissance et sa férocité. il peut infliger des dégâts massifs avec ses attaques aquatiques.", water, 2, 95, abilitys[38], abilitys[23]},
{"lokhlass", "lokhlass a un pelage épais qui le protège du froid. il est capable de nager dans des eaux glacées sans être affecté.", water, 3, 130, abilitys[38], abilitys[15]},
{"métamorph", "métamorph peut prendre l'apparence de n'importe quel autre pokémon. il utilise cette capacité pour tromper ses ennemis.", normal, 1, 48, abilitys[56], abilitys[58]},
{"évoli", "évoli a plusieurs évolutions possibles en fonction de facteurs tels que l'amitié avec son dresseur ou l'environnement.", normal, 1, 55, abilitys[23], abilitys[24]},
{"aquali", "aquali évolue à partir d'évoli lorsqu'il est exposé à une pierre eau. il a une excellente natation.", water, 2, 65, abilitys[23], abilitys[11]},
{"voltali", "voltali évolue à partir d'évoli lorsqu'il est exposé à une pierre foudre. il peut générer de l'électricité à partir de ses poils.", electric, 2, 65, abilitys[22], abilitys[24]},
{"pyroli", "pyroli évolue à partir d'évoli lorsqu'il est exposé à une pierre feu. il a une fourrure enflammée et peut contrôler le feu.", fire, 2, 65, abilitys[6], abilitys[37]},
{"porygon", "porygon est un pokémon artificiel créé par la science. il peut se déplacer à travers les données informatiques.", normal, 1, 65, abilitys[22], abilitys[14]},
{"amonita", "amonita était autrefois un pokémon marin. il a été ressuscité à partir d'une ancienne coquille fossilisée.", rock, 1, 35, abilitys[38], abilitys[58]},
{"amonistar", "amonistar évolue à partir d'amonita. il a une coquille très dure et peut nager à des vitesses incroyables.", rock, 2, 70, abilitys[38], abilitys[58]},
{"kabuto", "kabuto était autrefois un pokémon marin. il a été ressuscité à partir d'une ancienne carapace fossilisée.", rock, 1, 30, abilitys[47], abilitys[58]},
{"kabutops", "kabutops évolue à partir de kabuto. il a des lames tranchantes sur ses pattes et peut nager à des vitesses élevées.", rock, 2, 60, abilitys[47], abilitys[58]},
{"ptéra", "ptéra est un pokémon préhistorique qui peut voler à des altitudes extrêmement élevées. il est le symbole de la vie éternelle.", rock, 3, 80, abilitys[32], abilitys[58]},
{"ronflex", "ronflex est un pokémon paresseux qui passe la majeure partie de la journée à dormir. il a un appétit insatiable.", normal, 1, 160, abilitys[11], abilitys[24]},
{"artikodin", "artikodin est l'un des pokémon légendaires. il contrôle la glace et peut créer d'énormes tempêtes de neige.", ice, 1, 90, abilitys[8], abilitys[36]},
{"électhor", "électhor est l'un des pokémon légendaires. il génère de l'électricité pendant les orages et peut créer des éclairs.", electric, 1, 90, abilitys[22], abilitys[37]},
{"sulfura", "sulfura est l'un des pokémon légendaires. il contrôle le feu et peut créer des flammes intenses.", fire, 1, 90, abilitys[6], abilitys[37]},
{"minidraco", "minidraco est un dragon jeune qui aime jouer et s'amuser. il évolue en draco à mesure qu'il grandit.", dragon, 1, 41, abilitys[39], abilitys[32]},
{"draco", "draco est plus mature que minidraco. il a des ailes qui lui permettent de voler et de se déplacer rapidement.", dragon, 2, 61, abilitys[39], abilitys[32]},
{"dracolosse", "dracolosse est le stade final de l'évolution de minidraco. il est extrêmement puissant et peut infliger des dégâts massifs avec ses attaques.", dragon, 3, 91, abilitys[39], abilitys[37]},
{"mewtwo", "mewtwo est l'un des pokémon légendaires les plus puissants. il a des pouvoirs psychiques incroyables et peut contrôler les esprits.", psychic, 1, 106, abilitys[43], abilitys[50]},
{"mew", "mew est un pokémon mythique rare. il est dit avoir l'adn de tous les pokémon et peut utiliser toutes les attaques.", psychic, 1, 100, abilitys[43], abilitys[24]},

};
std::vector<Trainer> trainers = {
   {"player","","",0,100,{}},
   {"rival","","allez viens te battre !",100,100,{}},
   {"dresseur normal", "smith", "la norme, mais solide !", 200, 3, {}},
   {"dresseur aquatique", "jones", "naviguons ensemble !", 220, 3, {}},
   {"dresseur végétal", "williams", "les plantes m'accompagnent !", 250, 4, {}},
   {"dresseur pyro", "taylor", "le feu qui brûle en moi !", 300, 4, {}},
};


Texture2D pokeballSprite;


void LoadTrainers()
{
	trainers[2].AddPokemon(allPokemons[15]);
	trainers[2].AddPokemon(allPokemons[19]);
	trainers[2].AddPokemon(allPokemons[28]);

	trainers[3].AddPokemon(allPokemons[40]);
	trainers[3].AddPokemon(allPokemons[53]);
	trainers[3].AddPokemon(allPokemons[68]);

	trainers[4].AddPokemon(allPokemons[78]);
	trainers[4].AddPokemon(allPokemons[92]);
	trainers[4].AddPokemon(allPokemons[106]);
	trainers[4].AddPokemon(allPokemons[120]);

	trainers[5].AddPokemon(allPokemons[8]);
	trainers[5].AddPokemon(allPokemons[26]);
	trainers[5].AddPokemon(allPokemons[34]);
	trainers[5].AddPokemon(allPokemons[49]);
}

Ability getAbility(int index)
{
	return abilitys[index];
}

Pokemon getPokemon(int index)
{
	return allPokemons[index];
}

Pokemon getRandomPokemon()
{
	int randomPokemon = GetRandomValue(0, allPokemons.size() - 1);
	return allPokemons[randomPokemon];
}

Ability getRandomAbility(PokeType type)
{
	std::vector<Ability> abilitysByType;

	for (int i = 0; i < abilitys.size() - 1; i++)
	{
		if (abilitys[i].GetType() == type)
		{
			abilitysByType.push_back(abilitys[i]);
		}
	}

	int randomAbility = GetRandomValue(0, abilitysByType.size() - 1);

	return abilitysByType[randomAbility];
}

Trainer& getTrainer(int index)
{
	return trainers[index];
}



void LoadPokeSprites()
{
	Image pokeballImage = LoadImage("resources/ButtonsIcons/pokeball_1.png");
	pokeballSprite = LoadTextureFromImage(pokeballImage);
	UnloadImage(pokeballImage);

	for (int i = 0; i < allPokemons.size(); i++) {
		std::string imagePath = "resources/pokemonsImages/pokemon_" + std::to_string(i + 1) + ".png";
		Image pokemonImage = LoadImage(imagePath.c_str());
		Texture pokemonSprite = LoadTextureFromImage(pokemonImage);
		allPokemons[i].SetSprite(pokemonSprite);
		allPokemons[i].SetPokeballSprite(pokeballSprite);
		UnloadImage(pokemonImage);
	}
}

void UnloadPokeSprites()
{
	for (int i = 0; i < allPokemons.size(); i++) {
		UnloadTexture(allPokemons[i].GetSprite());
	}
	UnloadTexture(pokeballSprite);
}

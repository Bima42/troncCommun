Debian : 
	- Plus simple a prendre en main et a setup
	- ISO = netinst debian x64
	*- Pas d'interface graphique;
	- logiciel libre, au code source ouvert
	- base sur linux
LVM, c'est quoi ? 
	- Gestionnaire de volumes logiques pour Linux
	- Fourni une couche d'abstraction entre l'espace stockage physique et le systeme : creer partitions virtuelles faciles a gerer
	- Composer par les elements suivants :
		Volume Physique (PV) : espaces stockages traditionnels sur lesquels LVM cree ses volumes logiques
		Groupes de Volumes (VG) : groupes de volumes physiques reunis par LVM en un seul "disque virtuel". Un VG contient des volumes logiques qui sont repartis par LVM sur les differents volumes physiques
		Volumes Logiques (LV) : "partitions virtuelles" constitues d'etendues de blocs physiques reunis en un seul espace de stockage reunis en un seul espace de stockage et rendus lisibles par le systeme
		Etendue Physique (PE) : petit bloc de disques (environ 4Mo) qui peut etre affecte a un volume logique
	Peut le voir comme "partitions dynamiques" -> on peut creer, redimensionner et supprimer les LVM partitions ("Logical Volumes")
	Avantage : si on a plus d'un hard-disk, on peut. En plus on est pas limite par la taille d'un seul disque
			on peut creer des snapshot (read only) de n'importe quel LV (utile pour back up de serveurs etc ...)

Snapshot : 
	- aussi appele "instantane de stockage"
	- realiser une copie de donnees stockees sur un systeme de stockage ou copie des modifications apportees a ces donnees
	= "photo" des donnees stockees sur un systeme de stockage a un instant precis
	- permet a utilisateur de restaurer les donnees telles quelles etaient lors de la capture (permet de proteger donnees en cas d'erreur de manipulation humaine ou de corruption de donnees)
	- peut en realiser plusieurs, et donc de choisir lequel on souhaite restaurer
	- chacun est stocker sur disque virtuel different
	- differents snapshot sont lies par relation parent-enfant et forment arborescence. Chacun d'eux forment une nouvelle branche d'arbre

Partition : 
	- Chiffrer les donnees d'un disque permet d'assurer une certaines confidentialite de ces donnees
	- Partition = section d'un support de stockage (disque dur, SSD ..). Partitionner ca vise a diviser le support en partitions dans lesquelles le systeme d'exploitation peut gerer les informations separemment
	- Autre que la rapidite d'acces, sans partionnement, a la suite d'un crash il faudrait reinstaller le systeme d'exploitation
	- En bref, il permet de proteger et isoler les differents composants du systeme de fichiers
	/boot contient noyau de demarrage et des fichiers (autorise que par root)
	/tmp contient fichiers temporaires
	/srv contient fichiers servis par un service type web
	/usr contient majorite des utilitaires et fichiers systeme
	/var partition contient des fichiers variables pendant la vie du systeme (mails, bases de donnees d'un service)
	
LVM :
	Commandes a connaitre : 
		- Executer les commandes en tant que root (SUDO) par exemple : //sudo lvs
		- afficher les details succincts des volumes physiques : //pvs
		- afficher les details succincts des groupes de volumes : //vgs
		- afficher les details succincts des volumes logiques : //lvs
		- trouver le chemin d'acces a notre volume physique : //lvdisplay puis trouver le LV Path
		- creer partition LVM vide sur nouveau disque : //fdisk ou gparted
		- creer un volume physique sur nouveau disque : //pvcreate/nompartition
		- verifier nom de cette partition : //sudo pvs

Aptitude/Apt, difference : 
	aptitude : 
		- plus convivial / 
		- ajoute une couche d'abstraction a partir de apt-get, apt-cache ... / 
		- haut niveau d'abstraction / 
		- plus recent et censer etre plus facile a utiliser / 
		- fournit un une interface menu terminal (un peu comme Synaptic) / 
		- supprime automatiquement les paquets eligibles
		- EN BREF : remplit les fonctions apt-get mais ajoute aussi certains des outils d'apt-get suplementaires comme apt-cache ou apt-mark
		- EN PLUS : si des actions que l'on veut faire provoque un conflit, aptitude suggere plusieurs solutions, pas apt-get
	apt_get : 
		- plutot utiliser par programme de niveau superieur / 
		- facile a utiliser par utilisateurs / 
		- pas d'interface menu
		- requiert commande separes pour les paquets eligibles
	Mais les deux utilisent les memes referentiels

	SUPPLEMENT : il existe un outil appele Wajig 
		c'est un repartiteur, une enveloppe de tous les outils d'apt-get
		applique sudo lorsque c'est necessaire
		exemple : si on tape //wajig install foo
			il nous montrera que install est fourni par apt-get et qu'il requiert des privileges admin
			puis executera //sudo apt-get install foo

AppArmor : 
	Logiciel de securite sous Linux
	permet a admin systeme d'associer a chaque progamme un profil de securite qui restreint ses acces au systeme d'exploitation
	permet d'utiliser le controle d'acces obligatoire (MAC, Mandatory access control)
	alternative a SELinux car critiquer pour etre difficile a parametrer et a maintenir

SSH : ACTIF UNIQUEMENT SUR LE PORT 4242 / NE DOIT PAS POUVOIR SE CONNECTER PAR SSH AVEC UTILISATEUR ROOT
	- protocole permettant etablir communication chiffree donc securisee entre une machine locale et une distante
	- on s'en sert entre autre pour se connecter a distance au terminal, transferer des fichiers en ligne de commande etc
	- activer systeme ssh : // sudo systemctl start ssh
	- verifier ce qui est installer : // ssh -V
	-se connecter en SSH : // ssh <nom_utilisateur>@<ipaddress> -p <num_port> 

UFW : SEULEMENT LE PORT 4242 OUVERT
	- verifier statut actuel de ufw : // sudo ufw status
	- s'il est inactif, pour l'activer : // sudo ufw enable
	- afficher l'etat des regles ufw : // sudo ufw status verbose
	- ajouter une regle de connexion entrante : // sudo ufw allow 8080 (pour port 8080)
	- supprimer une regle : // sudo ufw delete [numero] : numero ici correspond au numero dans le nombre d'autorisation de ufw, pas le numero du port !
	- si IPV6 n'est pas activer : modifier le fichier /etc/default/ufw et d'y mettre ceci : IPV6 =yes et relancer ufw : // sudo ufw reload

TTY : 
	- Unix commands that prints the name of the terminal connected to standard input
	 By defaults, Ubuntu has 7 tty's

UTILISATEURS :
	- Ajouter un utilisateur : //sudo adduser username
		cela va ajouter les infos dans // /etc/passwd   /  /etc/group   /   /etc/shadow
		aussi creer un user home directory dans //  /etc/skel
	- Creer un groupe (avoir droits sudo ou root) : // (sudo) groupadd namegroup
	- Add existing user account to a group : // sudo usermod -aG namegroup username
	 	-a to append : add the user to the supplementary group. Only used with -G
		-G : mean groups / so with -a its to append in a group 

SUDO :
	- permet de gerer, autoriser ou refuser a un utilisateur l'execution de taches privilegiees avec ou sans saisie de mdp
	- GESTION DES DROITS : dans fichier // /etc/sudoers
	- Tous les fichiers du répertoire /etc/sudoers.d/ ne finissant pas par ~ ou ne contenant pas un . sont lus et analysés lorsque l'on utilise la commande sudo
	- Add user to sudo : // sudo usermod -aG sudo username
	- Synthaxe d'une regle sudo (cf screenshot) : // %sudo     ALL=(ALL:ALL)  ALL
	- MODIFIER LE FICHIER EN QUESTION : // sudo visudo
		Il effectue une vérification de l'intégrité du fichier après modification avant de l'enregistrer. En cas d'erreur lors de la modification, le nouveau fichier n'est pas enregistré
		A la fermeture, directement edite
		Peut donc ajouter des lignes dans ce fichier afin d'instruire des regles particulieres
		cf SCREEN DANS DOSSIER
	- INSTALLER PAM (Pluggable Authentication Modules) : // sudo apt-get install libpam-cracklib
		Edit the file : // vi /etc/pam.d/common-password
		Find so informations in it : retry, minlen, difok... Its all about changing those values
	//	Tout savoir sur PAM : www.tecmint.com/configure-pam-in-centos-ubuntu-linux/
	//	https://support.huaweicloud.com/intl/en-us/hss_faq/hss_01_0043.html
	- POUR LE GROUPE SUDO : 
		-Message d'erreur en cas de mauvais mdp : fichier dans // /etc/sudoers
			commande : // sudo visudo
			add la ligne suivante dans Defaults : // Defaults badpass_message="message"
		-3 essais pour sudo : idem
			add dans Default : // Defaults passwd_tries=3
		-Path utilisables par sudo : idem
			add dans Defaults : // Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
		-ARCHIVER LES COMMANDES SUDO ??????
			a verifier : // sudo grep sudo /var/log/auth.log > namefile.txt
			ou bien :    // sudo nano /var/log/auth.log.
   						//  sudo grep sudo /var/log/auth.log.
   						//  sudo grep sudo /var/log/auth.log > sudolist.txt.
    					//  sudo nano /home/USERNAME/.bash_history.
		-ACTIVER MODE TTY ???
			a verifier : dans le fichiers sudoers dans Defaults : // Defaults requiretty
SCRIPT :
	- COMMANDE WALL :
		write a message to all users
		displays a message, or the contents of a file, or otherwise its standard input, on the terminals of all currently logged in users
        command will always put a carriage return and new line at the end of each line
		-g : limit printing message to members of group defined
		-n : suppress the banner
	- PRINTF : 
		\n for newline, \r for carriage retyrn ...
		'-' left align the printed text
		https://linuxize.com/post/bash-printf-command/
	- df :
		= disk free
		commande UNIX pour afficher la valeur d'espace disque disponible des systemes de fichier dont l'utilisateur possede l'acces
		df -h : espace disque libre est liste en format visible pour l'homme
	- awk : 
		agit comme un filtre programmable prenant une série de lignes en entrée (sous forme de fichiers ou directement via l'entrée standard) et écrivant sur la sortie standard, qui peut être redirigée vers un autre fichier ou programme
		syntaxe est inspiree du C : awk [options] [programme] [fichier]
	- top :
		sed to show the Linux processes. It provides a dynamic real-time view of the running system
		-b : Batch mode = send output from top to file or any other programs
		-n 1 : this command keep refreshing umtil we press 'q' -> with this top command will automatically exit after 1 number of repetition
	- netstat : 
		-a : list all connections
		-at : To list out only tcp connections use the -t options
		-ant :  command shows ALL TCP connections with NO dns resolution
		-n : for numeric, print address with numeric format
	- id : 
		print real and effective user and groups IDs
		-u : print only the effective user ID
	- who :
		show who is connected
		-q : Affiche  uniquement les noms d'utilisateurs et le nombres de personnes connectées, priorité sur toutes les autres options


==============================================================SCRIPT BASH====================================================================

	- Architecture : 
		Commande // arch : same as uname -m : output = x86_64
				// dpkg --print-architecture : display Debian operating system is 64-bit
				// uname -a : display linux system's OS type
	- Nombre de processeurs physiques : 
		Count the number of lines starting with processor in /proc/cpuinfo : // grep -c ^processor /proc/cpuinfo
																autre piste: // awk '/^processor/{n+=1}END{print n}' /proc/cpuinfo

	- Nombre de processeurs virtuels :
   		Command : // cat /proc/cpuinfo | grep processor | wc -l
	- Memory Usage : 
		Command : // free
		La commande nous fournit toutes les informations, avec grep etc il y a moyen de faire la ligne attendue par le sujet
	- Memory Usage + Disk Usage + CPU Load (taux utilisation processeurs sous forme de pourcentage)
		// free -m | awk 'NR==2{printf "Memory Usage: %s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }'
		// df -h | awk '$NF=="/"{printf "Disk Usage: %d/%dGB (%s)\n", $3,$2,$5}'
		// top -bn1 | grep load | awk '{printf "CPU Load: %.2f\n", $(NF-2)}' 
	- Heure/Date du dernier demarrage : 
		info est dispo dans : /proc/uptime 
		// last|grep boot
		// who -b : permet avoir le dernier reboot
	- LVM running ?????????
	- Numbers of TCP Connexions : 
		probably using : // netstat command with grep ...
		pistes : // netstat -an|grep ESTABLISHED | grep -w 1935
				 // netstat -ant | grep ESTABLISHED | wc 
	- Numbers of users logged in :
		probably using : // id command	
		or : // who command : who | sort -uk1,1 | wc -l
	- MAC adress :
		// cat /sys/class/net/*/address
		// or : ifconfig <Interface ex:eth0,eth1> | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}'
	- IPV4 address :
		// hostname -I
		// or : /sbin/ip -o -4 addr list eth0 | awk '{print $4}' | cut -d/ -f1
		// or : ifconfig | awk '/inet addr/{print substr($2,6)}'
	- Nombre de commandes sudo : 
		Probablement se servir du file ou sont stockees les commandes sudo et incrementer un compteur a chaque commande tapees


POUR LE PROJET : 
	*Hostname (nom machine) = tpauvret42
	*Installer et configurer sudo
	*2 utilisateurs : root + tpauvret (doit appartenir au groupe sudo, et au groupe user42)

BIBLE : 
https://baigal.medium.com/born2beroot-e6e26dfb50ac

=========================================================DEMARCHE SUIVIE POUR PROJET=========================================================

1/ Install VM without SSH, choose LVM with encryption
2/ Sudo : 
	Login as root : // su -
	Install sudo : // apt-get update -y
   				   // apt-get upgrade -y
				   // apt-get install sudo
	
	Add user in sudo group : // su -
							 // usermod -aG sudo username
	Check user in sudo group : // getent group sudo
	Open sudoers file : // sudo visudo
	Add this line in file : // username		ALL=(ALL) ALL
3/ Installing git : // apt-get install git -y
	Check version : // git --version

4/ Installing VIM : // sudo apt-get install vim
5/ Install SSH :
	// sudo apt-get update
	// sudo apt install openssh-server
	Check SSH server status : // sudo systemctl status ssh
	Restart the service : // service shh restart
	Changing default port to 4242 : // sudo vim /etc/ssh/sshd_config
									// change the line #Port22 to Port 4242
	Restart the service

6/ Install UFW : 
	Install : // apt-get install ufw
	Enable : // sudo ufw enable
	Check status : // sudo ufw status numbered
	Configure rules : // sudo ufw allow ssh
	Configure port rules : // sudo ufw allow 4242
	(EVALUTION) : Delete a new rule : // sudo ufw status numbered // sudo ufw delete (number of the rule)

7/ Password policy : 
	Install PAM.D : // sudo apt-get install libpam-pawquality
	Change the length : // sudo vim /etc/pam.d/common-password
	Find the line : // password [success=2 default=ignore] pam_unix.so obscure sha512
	Add extraline : // minlen=10
	Find line : // password		requisite		pam_pwquality.so retry=3
	Add values after retry : // lcredit =-1
    Add this after : // ucredit=-1 dcredit=-1 maxrepeat=3 usercheck=0 difok=7
					 // enforce_for_root
	Password expiration : // sudo vim /etc/login.defs
		find this part : // PASS_MAX_DAYS 30 -> PASS_MAX_DAYS 30
						 // PASS_MIN_DAYS 0 ->  PASS_MIN_DAYS 2
						 // PASS_WARN_AGE 7 ->  PASS_WARN_AGE 7
		then : // sudo reboot

8/ Create group : 
	// sudo groupeadd name_group
	check si le groupe est cree : // getent group

9/ Create user : 
	// sudo adduser new_username
	Assigning an user to a group : // sudo usermod -aG name_group username
	Check assignation : // gentent group name_group
	Check which groups user account belongs : // groups

10/ Configuring sudoers group : 
	// sudo vim /etc/sudoers
	Add those lines in Defaults : // Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
								  // Defaults	passwd_tries=3
								  // Defaults	badpass_message="Password is wrong, please try again !"
								  // Defaults	logfile="/var/log/sudo/sudo.log"
								  // Defaults 	log_input, log_output
								  // Defaults	requiretty

11/ Change hostname : 
	Check current hostname : // hostnamectl
	Change hostname : // hostnamectl set-hostname new_hostname
	Change /etc/hosts file : // sudo vim /etc/hosts
	Change old name with new name
	Reboot and check changes : // sudo reboot

12/ Crontab configuration and script : 
	Install netstat tools : // sudo apt-get install -y net-tools
	Place monitoring.sh in : // /usr/local/bin
	Do the script
	Add rule that script would execute without sudo password :
		Open sudoers file : // sudo visudo
		Add line : // username ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh
	Reboot : // sudo reboot
	Execute script as su : // sudo /usr/local/bin/monitoring.sh
	Open crontab  : // sudo crontab -u root -e
	Add rule at the end : // */10 * * * * /usr/local/bin/monitoring.sh
		10 here means every 10 minutes the script will show


	

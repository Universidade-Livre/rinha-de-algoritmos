Para rodar a solução basta executar:

dotnet run pathdoarquivo -c Release

ou,

dotnet build -c Release
Em seguida executar o arquivo pelo terminal na pasta bin/Release/trevisharp.exe com o path como parâmetro.
Considerando-se que desta forma não se contará tempo de compilação.

Saídas:
Duas linhas: 1 - tempo usando a classe Stopwatch recomentada para esse tipo de test (a o tempo apresentado, sem segundos, inclui tempo de abertura do arquivo); 2 - Valor da solução.

Sobre a solução:
Foi utilizado um algoritmo guloso até o tamanho de 2 vezes o maior espaço de plantio da semente, assim, obtendo solução ótima utilizando programação dinâmica para as últimas semenetes. 

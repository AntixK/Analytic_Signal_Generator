clc;
close all;

W1 = 0.05;
W2 = 0.45;
a = 0.05;
w1 = W1 - a :0.01: W1 + a;
H1 = sin(pi/(4*a)*[w1 - (W1 -a)]).^2;
w2 = W1 + a :0.01: W2 - a;
w3 = W2 - a :0.01: W2 + a;
H3 = cos(pi/(4*a)*[w3 - (W2 -a)]).^2;

figure
hold on
plot(w1,H1,'r');
plot(w2, ones(1,length(w2)),'r');
plot(w3,H3,'r');
grid on
title('Desired Magnitude Respose of Analytic Signal');
xlabel(' Normalized Frequency \omega');
ylabel('|H(\omega)|');

%% Obtaining Samples

A = load('A_5000.dat');
B = load('B_5000.dat');

figure
hold on
plot([-2499:2500],A,'linewidth',2);
plot([-2499:2500],B,'linewidth',2);
xlim([-19 20]);
grid on
title('Analytic Signal');
xlabel('Time Samples');
ylabel('Amplitude');
legend('Real Part','Imaginary part');

%% Constructing the Analytic Signal
Z = A + j*B;

figure
freqz(Z);
title('Frequency Response of Analytic Signal');



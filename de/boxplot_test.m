%%箱型图测试
x = f3fluctuate;
subplot(211)
boxplot(x(:,1))
subplot(212)
plot(x(:,2),'.')
hold on
plot([0 10000],[450000 450000])
% A = randn(100,4);
% R = corrcoef(A)
suptitle('f3')
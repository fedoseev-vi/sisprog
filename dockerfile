FROM debian
COPY userscript /userscript
RUN chmod +x userscript
RUN useradd test && usermod -p 12345 test
CMD ./userscript
